#!/usr/bin/env python
# encoding: utf-8
# by netcan @ https://github.com/netcan/Leetcode-Rust
import requests, os
import requests_cache
import re, threading
import html
import subprocess, time
from requests.utils import requote_uri
from collections import Counter
from datetime import datetime
from json.decoder import JSONDecodeError
import json

CODE_TEMPLATE = \
"""// Author: Netcan @ https://github.com/netcan/Leetcode
// Zhihu: https://www.zhihu.com/people/netcan
{code}
"""

REPO_README_TEMPLATE = """
## Leetcode-kLingHui
本项目记录我的刷题过程。
本项目由`crawler.py`生成，源代码在https://github.com/netcan/Leetcode-Rust/crawler.py
代码自动爬取Leetcode-cn.com网站获取个人提交记录。使用方法：登陆Leetcode后记录cookie，设置环境变量`LEETCODE_COOKIE`，然后执行本脚本就能抓取指定语言的个人提交记录。
目前已解决的题目（{solv_question_num} 个，其中简单{easy_num} 个，中等{medium_num} 个， 困难{hard_num} 个）：
{solv_question_list}
"""

QUESTION_TEMPLATE = \
"""# {question_name} {question_level}
- 题目地址: [{question_url}]({question_url})
- 执行时间: {runtime} 
- 内存消耗: {mem_usage}
- 通过日期: {time}
## 题目内容
{question_content}
## 解法
```{lang}
{code}
```"""

class Leetcode:

    LEETCODE_URL = 'https://leetcode-cn.com'
    SIGN_IN_URL = LEETCODE_URL + '/accounts/login/'
    LEETCODE_LIST_URL = 'https://leetcode-cn.com/api/problems/all/'
    LEETCODE_GRAPHQL = 'https://leetcode-cn.com/graphql'
    REPO_URL = 'https://github.com/netcan/Leetcode-Rust'
    
    def __init__(self):
        self.user_agent = r'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Safari/537.36'
        self.headers = {'User-Agent': self.user_agent, 'Connection': 'keep-alive', 'Referer': 'https://leetcode.com/accounts/login/',
                        "Content-Type": "application/json"}
        
        self.cached_solved_quest = {}

    def login(self):
        with (open("config.json","r")) as f:
            temp = json.loads(f.read())
            username = temp['username']
            password = temp['password']
            self.time_control = 3600*24*temp['time']
        self.client = requests.session()
        self.client.encodling = "utf-8"
        while True:
            try:
                self.client.get(self.SIGN_IN_URL, verify=False)

                login_data = {'login': username, 
                    'password': password
                }
                
                result = self.client.post(self.SIGN_IN_URL, data=login_data, headers=dict(Referer=self.SIGN_IN_URL))
                
                if result.ok:
                    print ("Login successfully!")
                    break
            except:
                print ("Login failed! Wait till next round!")
                time.sleep(5)
        
    def get_solved_list(self):
        with requests_cache.disabled():
            print("solved_list: ", self.client.get(Leetcode.LEETCODE_LIST_URL).json())
            solv_list = self.client.get(Leetcode.LEETCODE_LIST_URL).json()
            return [{
                "question_slug": v['stat']['question__title_slug'],
                "question_id": v['stat']['frontend_question_id'], # 用页面上显示的id
                "question_title": v['stat']['question__title'],
                "question_difficulty": v['difficulty']['level']
                } for v in
                    self.client.get(Leetcode.LEETCODE_LIST_URL).json()['stat_status_pairs']
                if v['status'] == 'ac'
            ]

    def get_submit_list(self, question_slug):
        with requests_cache.disabled():
            params = {'operationName': "Submissions",
                        'variables':{"offset":0, "limit":20, "lastKey": '', "questionSlug": question_slug},
                            'query': '''query Submissions($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String!) {
                                submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug) {
                                lastKey
                                hasNext
                                submissions {
                                    id
                                    statusDisplay
                                    lang
                                    runtime
                                    timestamp
                                    url
                                    isPending
                                    memory      
                                    __typename   
                                }
                                __typename
                            }
                        }'''
                    }
            data = json.dumps(params).encode('utf-8')
            
            temp = self.client.post(Leetcode.LEETCODE_GRAPHQL,headers = self.headers,data=data).json()
            submit_list = [item for item in
                           self.client.post(Leetcode.LEETCODE_GRAPHQL,headers = self.headers,
                           data=data).json()['data']['submissionList']['submissions']
                           if item['statusDisplay'].lower() == 'accepted']
            return submit_list

    def get_source(self, url): # /submissions/detail/14313499/
        req_url = self.LEETCODE_URL + url
        try:
            src = re.search('submissionCode: \'(.*)\',', self.client.get(req_url).text).group(1)
            return src.encode('cp1252', 'backslashreplace').decode('unicode-escape')
        except AttributeError:
            pass

    def get_question_content(self, question_slug): # /problems/number-of-enclaves/
        params = {'operationName':'questionData',
            'variables':{'titleSlug':question_slug},
            'query':'''query questionData($titleSlug: String!) {
            question(titleSlug: $titleSlug) {
                questionId
                questionFrontendId
                boundTopicId    
                title    
                titleSlug
                content
                translatedTitle
                translatedContent
                isPaidOnly
                difficulty
                likes
                dislikes
                isLiked
                similarQuestions
                contributors {
                    username
                    profileUrl
                    avatarUrl
                    __typename
                    }    
                langToValidPlayground
                topicTags {
                    name
                    slug
                    translatedName
                    __typename
                }    
                companyTagStats
                codeSnippets {      
                    lang
                    langSlug
                    code
                    __typename
                }   
                stats  
                hints   
                solution {
                    id
                    canSeeDetail
                    __typename
                }    
                status    
                sampleTestCase    
                metaData    
                judgerAvailable    
                judgeType    
                mysqlSchemas    
                enableRunCode    
                enableTestMode    
                envInfo    
                __typename  
                }
            }'''
        }

        
        data = json.dumps(params).encode('utf-8')
        temp = self.client.post(self.LEETCODE_GRAPHQL,headers = self.headers,data=data).json()
        question_content = self.client.post(self.LEETCODE_GRAPHQL,headers = self.headers,data=data).json()['data']['question']
        return question_content

    def output_source(self, lang='rust', lang_suffix='rs', max_threads=8):
        self.login()
        self.get_cached_solved_ques()
        solved_list = self.get_solved_list()
        threads = []
        for idx, question in enumerate(solved_list):
            print("processing: {}. {} ({}/{})".format(question["question_id"],
                                                      question["question_title"],
                                                      idx + 1, len(solved_list)))
            if question["question_title"] in self.cached_solved_quest:
                print("cached: ", question["question_title"])
                continue

            def process_submit_list(question_):
                try:
                    submit_list = self.get_submit_list(question_["question_slug"])
                except JSONDecodeError:
                    return
                for submit in submit_list:
                    if submit["lang"] == lang:
                        src = self.get_source(submit['url'])
                        if not src: continue

                        question_content = self.get_question_content(question_["question_slug"])
                        if question_content['translatedContent'] is None: continue
                        src = CODE_TEMPLATE.format(code=src)
                        question_id = question_["question_id"]
                        dir_name = "{}. {}".format(question_id, question_["question_title"])
                        if len(question_id) ==1:
                            dir_name = 'n000' + dir_name
                        if len(question_id) ==2:
                            dir_name = 'n00' + dir_name
                        if len(question_id) ==3:
                            dir_name = 'n0' + dir_name
                        if len(question_id) ==4:
                            dir_name = 'n' + dir_name

                        if not os.path.exists(dir_name):
                            os.mkdir(dir_name)
                        with open(os.path.join(dir_name, "main.{}".format(lang_suffix)), "wb+") as f:
                            f.write(src.encode('gb18030'))

                        with open(os.path.join(dir_name, "README.md"), "wb+") as f:
                            f.write(QUESTION_TEMPLATE.format(question_name = question_["question_title"],
                                                             question_level = ":star:" * question_["question_difficulty"],
                                                             question_url = self.LEETCODE_URL + "/problems/{}".format(question_["question_slug"]),
                                                             runtime = submit["runtime"],
                                                             mem_usage = submit["memory"],
                                                             time = datetime.fromtimestamp(int(submit["timestamp"])).strftime("%Y-%m-%d %H:%M"),
                                                             lang = lang,
                                                             question_content=html.unescape(question_content['translatedContent']).replace('<p>\xa0</p>', ''),
                                                             code = src).encode('gb18030'))
                        break # 只取最新的(第一条就是)

            while len(threads) >= max_threads:
                for thread in threads:
                    if not thread.is_alive():
                        threads.remove(thread)
                time.sleep(0.5)

            thread = threading.Thread(target=process_submit_list, args=(question,), daemon=True)
            thread.start()
            threads.append(thread)

        # 最后检查存活线程
        while len(threads) > 0:
            for thread in threads:
                if not thread.is_alive():
                    threads.remove(thread)

        self.__generate_readme()

    def get_cached_solved_ques(self):
        #if not os.environ.get('CACHED_SOLVED_QUES'): return
        pattern_name = re.compile('n(\d+)\. (.*)')
        for dir_name in os.listdir('.'):
            if not pattern_name.match(dir_name): continue
            self.cached_solved_quest[pattern_name.search(dir_name).group(2)] = True

    def __generate_readme(self):
        pattern_name = re.compile('n(\d+)\. (.*)')
        question_level = {
            1: 0, 2: 0, 3: 0
        }
        question_list = []
        for dir in os.listdir('.'):
            if not pattern_name.match(dir): continue
            # 更新难度
            level = open('{}/README.md'.format(dir), 'r',encoding= 'gb18030').readline().count(':star:')
            question_level[level] += 1
            question_list.append('{} {}'.format(dir, ':star:' * level))


        question_list.sort(key=lambda q: int(re.search(r"(\d+)\..*", q).group(1)))
        question_list = '\n'.join(
            map(lambda u: "- [{}]({})".format(
                u.lstrip('n0'), requote_uri(
                    (Leetcode.REPO_URL + '/tree/master/{}'.format(u.replace(':star:', ''))).strip()
                )
            ) , question_list)
        )

        with open("README.md", "w") as f:
            f.write(REPO_README_TEMPLATE.format(solv_question_num=sum(question_level.values()),
                                                easy_num=question_level[1],
                                                medium_num=question_level[2],
                                                hard_num=question_level[3],
                                                solv_question_list=question_list))


if __name__ == '__main__':
    requests_cache.install_cache('leetcode')
    lc = Leetcode()

    lc.output_source('cpp','.cpp')

    subprocess.run(["git", "add", "."])
    subprocess.run(["git", "commit", "-m", "commit by crawler.py @Netcan at {}".format(datetime.now().strftime("%Y-%m-%d %H:%M"))])
    subprocess.run(["git", "push", "-f", "origin", "master"])


