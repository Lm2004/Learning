from selenium import webdriver
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import time
import pandas as pd

driver = webdriver.Firefox()
driver.get('https://coinmarketcap.com')
website = list()
name = list()
GitHub = list()
Num = 0
m=0
for a in driver.find_elements_by_xpath('//a[@class="currency-name-container link-secondary"]'):
    website.append(a.get_attribute('href'))
print("done first step")
while Num < 100:
    name_1  = driver.find_elements_by_xpath('//a[@class="currency-name-container link-secondary"]')[m].text
    name.append(name_1)
    m = m + 1
    Num = Num + 1
print("done second step")
Number = 0
l = 0
t = 0
nolink = "No link"
while Number < 100: 
    driver.get(website[l])
    try:
        if driver.find_element_by_xpath('//span[contains(text(),"Checking your browser before accessing")]'):
            time.sleep(6)
    except:
        pass

    try:
        
        for GitHublink_get in driver.find_elements_by_xpath('//a[contains(text(),"Source Code")]'):
            GitHublink = (GitHublink_get.get_attribute('href'))
        GitHub.append(GitHublink)
    except:
        pass
    t = Number - 1
    if Number > 0:
        if GitHub[t] == GitHub[Number]:
            GitHub.pop()
            GitHub.append("No link")
        elif GitHub[t] == nolink:
            f = 0
            while f < t:
                if GitHublink == GitHub[f]:
                    GitHub.pop()
                    GitHub.append("No link")
                else:
                    pass
                f = f + 1
        else:
            pass        
    l = l + 1
    Number = Number + 1


data = pd.DataFrame({'name': name ,'link': website[0:100], 'GitHub': GitHub})
data.to_csv('Criptonic.csv', index=False, encoding='utf-8')
print(data)


