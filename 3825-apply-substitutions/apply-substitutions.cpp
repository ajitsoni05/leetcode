class Solution {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        // Build a map for quick lookup of substitutions
        unordered_map<string, string> substitutionMap;
        for (const auto& pair : replacements) {
            substitutionMap[pair[0]] = pair[1];
        }

        vector<string> resultParts;
        stringstream ss(text);
        string segment;

        while (getline(ss, segment, '%')) {
            if (substitutionMap.count(segment)) {
                // Recursively apply substitutions
                string substituted = applySubstitutions(replacements, substitutionMap[segment]);
                resultParts.push_back(substituted);
            } else if (!segment.empty()) {
                resultParts.push_back(segment);
            }
        }

        string finalResult;
        for (const string& part : resultParts) {
            finalResult += part;
        }

        return finalResult;
    }
};
