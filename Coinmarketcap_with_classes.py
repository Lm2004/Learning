from selenium import webdriver
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from time import sleep
from random import randint
import pandas as pd
from Classification import coinmarketcap


driver = webdriver.Firefox()
driver.get('https://coinmarketcap.com')
link = list()
name = list()
Github = list()
Number_of_elements = int(input("Number of coin: "))
if __name__ == "__main__":
    coinmarket = coinmarketcap(Number_of_elements, driver, link, name, Github)
    coinmarket.website()
    coinmarket.CoinName()
    coinmarket.Github_func()


data = pd.DataFrame({'name': name ,'link': link, 'GitHub': Github})
data.to_csv('Criptonic.csv', index=False, encoding='utf-8')
print(data)

