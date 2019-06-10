from selenium import webdriver
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import lxml.etree as LE
import requests
import time
import pandas as pd

driver = webdriver.Firefox()
driver.get('https://coinmarketcap.com/')

name = list()
website = list()
GitHub = list()
Numbers = 0
m = 0
t = 0
for a in driver.find_elements_by_xpath('//a[@class="currency-name-container link-secondary"]'):
    website.append(a.get_attribute('href'))

while Numbers < 100:
        name.append(driver.find_elements_by_xpath('//a[@class="currency-name-container link-secondary"]')[m].text)
        """
        try:
                #better to check if the element is present?
                driver.find_elements_by_xpath('//button[@class="banner-alert-close-button js-close"]')[0].click()
        except:
                pass
        
        for Coinlink_get in driver.find_elements_by_xpath('//a[@class="currency-name-container link-secondary"]')[m]:
                Coinlink = Coinlink_get.get_attribute('href')
        website.append(Coinlink)
        """
        m = m + 1
        Numbers = Numbers + 1

"""
if c<7:
        try:
                driver.get(website[m])
                for GitHublink_get in driver.find_elements_by_xpath('//a[contains(text(),"Source Code")]'):
                        GitHublink = GitHublink_get.get_attribute('href')
                GitHub.append(GitHublink)
        except:
                pass
        m = m + 1
        c = c + 1
        try:
                if website[t] == website[m]: #is this for checking for duplicates? use list comprehension to avoid duplicates
                        website.pop()
                        driver.get('https://coinmarketcap.com/')
                        for master in driver.find_elements_by_xpath('//a[@class="currency-name-container link-secondary"]')[m]:
                                master_1 = link.get_attribute('href')
                        website.append(master_1)
                else:
                        pass
        except:
                pass
        """


driver.quit()

df = pd.DataFrame({'name': name ,'link': website})
df.to_csv('Criptonic.csv', index=False, encoding='utf-8')
print(df)


