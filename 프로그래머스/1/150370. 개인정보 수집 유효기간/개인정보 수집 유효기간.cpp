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

unordered_map<char, int> option;

vector<int> parse_date(const string& date) {
    vector<int> date_info(3);
    date_info[0] = stoi(date.substr(0, 4));
    date_info[1] = stoi(date.substr(5, 2));
    date_info[2] = stoi(date.substr(8, 2));
    return date_info;
}

void cal_custom_info(vector<string>& privacies, vector<info>& custom_info) {
    custom_info.reserve(privacies.size());
    
    for (int i = 0; i < privacies.size(); i++) {
        info tmp_info;
        tmp_info.num = i + 1;
        tmp_info.year = stoi(privacies[i].substr(0, 4));
        tmp_info.month = stoi(privacies[i].substr(5, 2)) + option[privacies[i].back()];
        tmp_info.day = stoi(privacies[i].substr(8, 2)) - 1;
        
        if (tmp_info.day == 0) {
            tmp_info.month--;
            if (tmp_info.month == 0) {
                tmp_info.month = 12;
                tmp_info.year--;
            }
            tmp_info.day = 28;
        }

        while (tmp_info.month > 12) {
            tmp_info.year++;
            tmp_info.month -= 12;
        }
        
        custom_info.push_back(tmp_info);
    }
}

vector<int> ck_terms(const vector<int>& todays_info, const vector<info>& custom_info) {
    vector<int> res;
    res.reserve(custom_info.size());
    
    for (const auto& cus : custom_info) {
        if (cus.year < todays_info[0] || 
            (cus.year == todays_info[0] && cus.month < todays_info[1]) || 
            (cus.year == todays_info[0] && cus.month == todays_info[1] && cus.day < todays_info[2])) {
            res.push_back(cus.num);
        }
    }
    
    return res;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> todays_info = parse_date(today);
    vector<info> custom_info;
    
    for (const auto& term : terms) {
        option[term[0]] = stoi(term.substr(2));
    }
    
    cal_custom_info(privacies, custom_info);
    
    return ck_terms(todays_info, custom_info);
}