from selenium import webdriver
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from time import sleep
from random import randint
import pandas as pd
from bs4 import BeautifulSoup, SoupStrainer

with open("links.txt") as f:
    content = f.readlines()
content = [x.strip() for x in content] 
sub_name = list()
driver = webdriver.Firefox()
xo = list()

ivent_class = list()
temp = list()
temp_name = list()

name = list()
number = len(content)
ivent = list()
x = 0
while x < number:
    driver.get(content[x])
    sleep(randint(5,7))
    if driver.find_elements_by_xpath("/html[1]/body[1]/div[3]/div[1]/div[4]/div[2]/div[1]/div[2]/div[1]/table[1]/tbody[1]/tr[position()>2]/td[1]"):
        
    
        for more in driver.find_elements_by_xpath("/html[1]/body[1]/div[3]/div[1]/div[4]/div[2]/div[1]/div[2]/div[1]/table[1]/tbody[1]/tr/td/div[@class='button-sm']/a[1]"):
            links = (more.get_attribute('href'))
            
            temp.append(links)
    
        i = 0
        name_org = driver.find_element_by_xpath("//div[@id='content']//div[1]//div[1]//table[1]//tbody[1]//tr[3]//td[2]").text
        while i < len(temp):
            temp_name.append(driver.find_elements_by_xpath("/html[1]/body[1]/div[3]/div[1]/div[4]/div[2]/div[1]/div[2]/div[1]/table[1]/tbody[1]/tr[position()>2]/td[1]")[i].text)
            i = i + 1
    
        l = 0
        while l < len(temp):
            t = 0
            driver.get(temp[l])
            sleep(randint(5,7))
            if len(driver.find_elements_by_xpath("/html[1]/body[1]/div[3]/div[1]/div[4]/div[2]/div[1]/div[1]/div[1]/table[2]/tbody[1]/tr[position()>2]/td[3]")) == 1:
                xo.append(temp[l])
                name.append(name_org)
                sub_name.append(temp_name[l])
                ivent_class.append(driver.find_element_by_xpath("/html[1]/body[1]/div[3]/div[1]/div[4]/div[2]/div[1]/div[1]/div[1]/table[2]/tbody[1]/tr[position()>2]/td[2]").text)
                ivent.append(driver.find_element_by_xpath("/html[1]/body[1]/div[3]/div[1]/div[4]/div[2]/div[1]/div[1]/div[1]/table[2]/tbody[1]/tr[position()>2]/td[3]").text)
            elif len(driver.find_elements_by_xpath("/html[1]/body[1]/div[3]/div[1]/div[4]/div[2]/div[1]/div[1]/div[1]/table[2]/tbody[1]/tr[position()>2]/td[3]")) > 1:
                
                while t < len(driver.find_elements_by_xpath("/html[1]/body[1]/div[3]/div[1]/div[4]/div[2]/div[1]/div[1]/div[1]/table[2]/tbody[1]/tr[position()>2]/td[3]")):
                    xo.append(temp[l])
                    name.append(name_org)
                    sub_name.append(temp_name[l])
                    ivent.append(driver.find_elements_by_xpath("/html[1]/body[1]/div[3]/div[1]/div[4]/div[2]/div[1]/div[1]/div[1]/table[2]/tbody[1]/tr[position()>2]/td[3]")[t].text)
                    ivent_class.append(driver.find_elements_by_xpath("/html[1]/body[1]/div[3]/div[1]/div[4]/div[2]/div[1]/div[1]/div[1]/table[2]/tbody[1]/tr[position()>2]/td[2]")[t].text)
                    t = t + 1
            else:
                xo.append(temp[l])
                name.append(name_org)
                sub_name.append(temp_name[l])
                ivent_class.append("None")
                ivent.append("None")
            l = l + 1
    else:
        name_org = driver.find_element_by_xpath("//div[@id='content']//div[1]//div[1]//table[1]//tbody[1]//tr[3]//td[2]").text
        name.append(name_org)
        xo.append("None")
        ivent_class.append("None")
        sub_name.append("None")
        ivent.append("None")
    temp_name.clear()
    temp.clear()
    x = x + 1
    sleep(randint(3, 7))
    data = pd.DataFrame({'name': name ,'ХО': xo, 'Наименование ХО (ХП)': sub_name, 'вид РИД': ivent_class ,'Изобретение': ivent})
    data.to_csv('MIP.csv', index=False, encoding='utf-8')
    print(data)


data = pd.DataFrame({'name': name ,'ХО': xo, 'Наименование ХО (ХП)': sub_name, 'вид РИД': ivent_class ,'Изобретение': ivent})
data.to_csv('MIP.csv', index=False, encoding='utf-8')
print(data)
