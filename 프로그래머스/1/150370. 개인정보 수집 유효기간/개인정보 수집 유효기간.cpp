#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct info {
    int num;
    int year;
    int month;
    int day;
};
vector<int> todays_info;
vector<info> custom_info;
unordered_map<char, int> option;

void cal_custom_info (vector<string>& privacies) {
    for (int i=0; i<privacies.size(); i++) {
        info tmp_info;
        tmp_info.num = i+1;
        tmp_info.year = stoi(privacies[i].substr(0, 4));
        tmp_info.month = stoi(privacies[i].substr(5, 2)) + option[privacies[i].back()];
        tmp_info.day = stoi(privacies[i].substr(8, 2)) - 1;
        
        while (tmp_info.month > 12) {
            tmp_info.year++;
            tmp_info.month -= 12;
        }
        
        if (tmp_info.day == 0) {
            if (tmp_info.month == 1) {
                tmp_info.month = 13;
                tmp_info.year--;
            }
            tmp_info.month--;
            tmp_info.day = 28;
        }
        
        custom_info.push_back(tmp_info);
    }
}

vector<int> ck_terms () {
    vector<int> res;
    for (int i=0; i<custom_info.size(); i++) {
        info cus = custom_info[i];
        if (cus.year > todays_info[0]) continue;
        else if (cus.year < todays_info[0]) {
            res.push_back(cus.num); continue;
        } 
        else {
            if (cus.month > todays_info[1]) continue;
            else if (cus.month < todays_info[1]) {
                res.push_back(cus.num); continue;
            }
            else {
                if (cus.day > todays_info[2]) continue;
                else if (cus.day < todays_info[2]) {
                    res.push_back(cus.num);
                }
            }
        }
    }
    return res;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    string tmp = "";
    for (char c: today) {
        if (c != '.') {
            tmp += c; continue;
        }
        todays_info.push_back(stoi(tmp));
        tmp = "";
    }
    todays_info.push_back(stoi(tmp));
    
    for (int i=0; i<terms.size(); i++) {
        option[terms[i][0]] = stoi(terms[i].substr(2));
    }
    
    cal_custom_info(privacies);
    
    return ck_terms();
}