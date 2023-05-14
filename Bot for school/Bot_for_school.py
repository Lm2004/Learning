from selenium import webdriver
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from msedge.selenium_tools import Edge, EdgeOptions
from selenium.webdriver.common.action_chains import ActionChains
from time import sleep
from random import randint
import pandas as pd
from datetime import datetime
import arrow
import schedule
import time

timeout = 10
options = EdgeOptions()
options.use_chromium = True
options.add_argument("--user-data-dir=C:\\Users\\Hotkins\\AppData\\Local\\Microsoft\\Edge\\User Data")
options.add_argument("--start-maximized")
driverpath = "C:\\edgedriver\\msedgedriver.exe"
driver = Edge(driverpath, options=options)

driver.get("https://dnevnik.mos.ru")

time.sleep(10) 

try:

    driver.find_element_by_xpath('//div[@class="_2NATN"]').click()

except:

    pass

time.sleep(10)

def job(t, now_end, times):
    print(t)
    a,b = now_end.split(":")
    k = 0
    try:
        driver.find_elements_by_xpath('//div[@class="css-1dbjc4n r-1awozwy r-18olmwv r-1xfd6ze r-18u37iz r-1777fci"]')[times].click()
    except:
        k = 1
    
    if k ==0:
        
        time.sleep(10)

        driver.find_elements_by_xpath('//div[@class="css-901oao css-bfa6kz r-jwli3a r-1sprdvb r-ubezar r-16dba41 r-q4m81j"]')[1].click()

        driver.switch_to.window(driver.window_handles[1])

        time.sleep(20)

        driver.find_element_by_xpath('//div[@id="buttonsbox"]/button[2]').click()

        time.sleep(20)

        driver.find_element_by_xpath('//button[@class="ts-toggle-button"]').click()

        driver.find_element_by_xpath('//button[@class="join-btn ts-btn inset-border ts-btn-primary"]').click()

        maintenance = arrow.now()

        EndAt = maintenance.replace(hour = int(a), minute = int(b), second = 0)

        print(maintenance,': Maintenance in progress. Pausing until :',EndAt)

        pause.until(EndAt.naive)

        print("pause ended")

        driver.close()

        driver.switch_to.window(driver.window_handles[0])

        driver.back()

        driver.refresh()

    else:
        pass

        
    return


first = "08:30"
first_end = "09:15"

second = "09:30"
second_end = "10:15"

third = "10:30"
third_end = "11:15"

fourth = "11:30"
fourth_end = "12:15"

fifth = "12:30"
fifth_end = "13:15"

sixth = "13:25"
sixth_end = "15:10"

seventh = "15:15"
seventh_end = "15:00"

schedule.every().day.at(first).do(job, 'It is 8:30', first_end, 0 + 5)

schedule.every().day.at(second).do(job, 'It is 9:30', second_end, 1 + 5 )

schedule.every().day.at(third).do(job, 'It is 10:30', third_end, 2 + 5)

schedule.every().day.at(fourth).do(job, 'It is 11:30', fourth_end, 3 + 5)

schedule.every().day.at(fifth).do(job, 'It is 12:30', fifth_end, 4 + 5)

schedule.every().day.at(sixth).do(job, 'It is 13:25', sixth_end, 5 + 5) 

schedule.every().day.at(seventh).do(job, 'It is 15:15', seventh_end, 6 + 5)

while True:
    schedule.run_pending()
    
    time.sleep(10) 
