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
a=0
m = 0
t = 0
a += 1

if a<7:
        name_1  = driver.find_elements_by_xpath('//a[@class="currency-name-container link-secondary"]')[m].text
        name.append(name_1)
        try:
                #better to check if the element is present?
                driver.find_elements_by_xpath('//button[@class="banner-alert-close-button js-close"]')[0].click()
        except:
                pass
        m = m + 1
        a = a + 1
a = 0
m = 0
driver.get('https://coinmarketcap.com/')
if a<7:
        for link in driver.find_elements_by_xpath('//a[@class="currency-name-container link-secondary"]')[m]:
                Coinlink = link.get_attribute('href')
        website.append(Coinlink)
        m = m + 1
        a = a + 1
a = 0
m = 0
if a<7:
        try:
                driver.get(website[m])
                for link in driver.find_elements_by_xpath('//a[contains(text(),"Source Code")]'):
                        link_1 = link.get_attribute('href')
                website.append(link_1)
        except:
                pass
        m = m + 1
        """
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

df = pd.DataFrame({'name': name ,'link': website,'GitHub link': GitHub })
df.to_csv('Criptonic.csv', index=False, encoding='utf-8')
print(df)


