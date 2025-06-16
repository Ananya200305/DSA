class Solution {
public:
    string generateTag(string caption) {
        string res = "#";
        bool isFirstWord = true;
        bool buildingWord = false;
        string currentWord = "";

        for (int i = 0; i <= caption.size(); i++) {
            if (i == caption.size() || caption[i] == ' ') {
                // Process the current word
                if (!currentWord.empty()) {
                    // Remove non-letter characters from word
                    string clean = "";
                    for (char c : currentWord) {
                        if (isalpha(c)) clean += c;
                    }

                    if (!clean.empty()) {
                        if (isFirstWord) {
                            for (char c : clean) res += tolower(c);
                            isFirstWord = false;
                        } else {
                            res += toupper(clean[0]);
                            for (int j = 1; j < clean.size(); j++) {
                                res += tolower(clean[j]);
                            }
                        }
                    }
                    currentWord = "";
                }
            } else {
                currentWord += caption[i];
            }
        }

        // Truncate to 100 characters if needed
        if (res.size() > 100) {
            res = res.substr(0, 100);
        }

        return res;
    }
};
