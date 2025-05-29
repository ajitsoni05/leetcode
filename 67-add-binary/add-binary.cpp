class Solution {
public:
    string addBinary(string a, string b) {
        string temp(10000, '0');

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (int i = 0; i < (int)a.size(); i++) {
            temp[i] = a[i];
        }

        int carry = 0;
        int i = 0;

        for (; i < (int)b.size(); i++) {
            int num1 = temp[i] - '0';
            int num2 = b[i] - '0';

            int sum = (num1 ^ num2) ^ carry;
            temp[i] = sum + '0';

            carry = (num1 & num2) | (carry & (num1 ^ num2));
        }

        while (carry) {
            int num1 = temp[i] - '0';
            int sum = num1 ^ carry;
            temp[i] = sum + '0';

            carry = num1 & carry;
            i++;
        }

        int len = i;  // <- Make sure this is after carry propagation
        len = max(len,(int)a.size());

       temp = temp.substr(0,len);
       

        string result = temp;
        reverse(result.begin(),result.end());
      

        cout << "Length: " << len << "\n"; // Debug length
        cout << "Temp (reversed): " << temp.substr(0, i) << "\n"; // Debug raw reversed bits

        return result;
    }
};
