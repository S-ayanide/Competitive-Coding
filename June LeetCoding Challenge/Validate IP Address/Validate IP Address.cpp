class Solution {
public:
    string validIPAddress(string IP) {
        int deli;
        deli = IP.find('.');
        if (deli != string::npos) {
            //cout<<"ipv4"<<endl;
            deli = 0;
            for (int i = 0; i < 4; ++i) {
                if (deli >= IP.size()) {
                    //cout<<deli<<endl;
                    return "Neither";
                }
                int j;
                for (j = deli; j < IP.size(); ++j) {
                    if(IP[j] == '.') break;
                    else if(IP[j] < '0' || IP[j] > '9') {
                        //cout<<IP[j]<<endl;
                        return "Neither";
                    }
                }
                if (j - deli <= 0) {
                    //cout<<j<<' '<<deli<<endl;
                    return "Neither";
                }
                string sub = IP.substr(deli, j - deli);
                if(sub[0] == '0' && sub.size() > 1) return "Neither";
                int s = atoi(sub.c_str());
                if (s < 0 || s > 255) {
                    //cout<<s<<endl;
                    return "Neither";
                }
                deli = j + 1;
            }
            if (deli -1 < IP.size()) {
                //cout<<deli<<endl;
                return "Neither";
            }
            else return "IPv4";
        }
        else {
            deli = 0;
            for (int i = 0; i < 8; ++i) {
                if (deli >= IP.size()) return "Neither";
                int j;
                for (j = deli; j < IP.size(); ++j) {
                    if (IP[j] == ':') break;
                    else if(!(IP[j] >='0' && IP[j]<='9' || IP[j]>='a' && IP[j]<='f' || IP[j]>='A' && IP[j]<='F')) {
                        //cout<<IP[j]<<(IP[j]>='0')<<(IP[j]<='9')<<endl;
                        return "Neither";
                    }
                }
                if (j - deli <= 0 || j-deli > 4) return "Neither";
                deli = j + 1;
            }
            if (deli -1 < IP.size()) {
                //cout<< deli-1<<endl;
                return "Neither";
            }
            else return "IPv6";
        }
    }
};