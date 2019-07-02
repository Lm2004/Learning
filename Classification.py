class coinmarketcap:
    def __init__(self, Number_of_elements, driver, link, name, GitHub):
        self.name = name
        self.Number_of_elements = Number_of_elements
        self.driver = driver
        self.link = link
        self.GitHub = GitHub
    def website(self):
        i = ""
        for i in self.driver.find_elements_by_xpath('//a[@class="currency-name-container link-secondary"]'):
            self.link.append(i.get_attribute('href'))
        print("All href's in your pocket!")
    def CoinName(self):
        i = 0
        while i < self.Number_of_elements:
            Coin  = self.driver.find_elements_by_xpath('//a[@class="currency-name-container link-secondary"]')[i].text
            self.name.append(Coin)
            i = i + 1
        print("Coin captured!")
    def Github_func(self):
        GitHublink_get = ""
        i = 0
        nolink = "No link"
        print("Starting getting GitHub links!")
        while i < self.Number_of_elements:
            GitHublink_get = ""
            self.driver.get(self.link[i])
            try:
                if self.driver.find_element_by_xpath('//span[contains(text(),"Checking your browser before accessing")]'):
                    time.sleep(6)
            except:
                pass
            try:
        
                for GitHublink_get in self.driver.find_elements_by_xpath('//a[contains(text(),"Source Code")]'):
                    GitHublink = (GitHublink_get.get_attribute('href'))
                self.GitHub.append(GitHublink)
            except:
                pass
            t = i - 1
            if i > 0:
                if self.GitHub[t] == self.GitHub[i]:
                    self.GitHub.pop()
                    self.GitHub.append("No link")
                elif self.GitHub[t] == nolink:
                    f = 0
                    while f < t:
                        if GitHublink == self.GitHub[f]:
                            self.GitHub.pop()
                            self.GitHub.append("No link")
                        else:
                            pass
                        f = f + 1
                else:
                    pass
            print(self.GitHub[i])
            i = i + 1
        print("Github link getted!")

