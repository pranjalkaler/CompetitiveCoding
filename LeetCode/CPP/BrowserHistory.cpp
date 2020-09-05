// LeetCode: https://leetcode.com/problems/design-browser-history
// Author: Pranjal Kaler

#include <bits/stdc++.h>

class BrowserHistory {

    std :: deque<std :: string> history;
    int currentPage;
public:
    BrowserHistory(std :: string homepage) {
        history.push_back(homepage);
        currentPage = 0;
    }

    void visit(std :: string url) {
        while(currentPage != history.size() - 1)
            history.pop_back();

        history.push_back(url);
        ++currentPage;
    }

    std :: string back(int steps) {
        while(steps && currentPage) {
            currentPage--;
            steps--;
        }
        return history[currentPage];
    }

    std :: string forward(int steps) {
        while(steps && currentPage < history.size() - 1) {
            currentPage++;
            steps--;
        }
        return history[currentPage];
    }

    friend std :: ostream& operator<<(std :: ostream& os, const BrowserHistory& bh);
};

std :: ostream& operator<<(std :: ostream& os, const BrowserHistory& bh) {
    for(auto& page : bh.history) {
        os << "["<< page << "] ";
    }
    return os;
}

int main() {
    std :: shared_ptr<BrowserHistory> BH = std :: make_shared<BrowserHistory>("www.google.com");
    BH->visit("www.yahoo.com");
    BH->visit("www.cricinfo.com");
    BH->visit("www.iwillcrackfaang.com");

    std :: cout << *BH << std :: endl;

    std :: cout << BH->back(3) << std :: endl;
    std :: cout << BH->forward(2) << std :: endl;
    std :: cout << BH->back(1) << std :: endl;
    std :: cout << BH->forward(5) << std :: endl;

    BH->visit("www.betaisthebest.com");

    std :: cout << *BH << std :: endl;
    std :: cout << BH->back(3) << std :: endl;

    BH->visit("www.rcbwillloseagain.com");

    std :: cout << *BH << std :: endl;
    return 0;
}

/* Expected output:

[www.google.com] [www.yahoo.com] [www.cricinfo.com] [www.iwillcrackfaang.com] 
www.google.com
www.cricinfo.com
www.yahoo.com
www.iwillcrackfaang.com
[www.google.com] [www.yahoo.com] [www.cricinfo.com] [www.iwillcrackfaang.com] [www.betaisthebest.com] 
www.yahoo.com
[www.google.com] [www.yahoo.com] [www.rcbwillloseagain.com] 

*/
