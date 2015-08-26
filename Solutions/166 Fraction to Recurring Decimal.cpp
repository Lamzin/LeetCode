class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long _numerator = numerator;
        long long _denominator = denominator;

        if (_denominator == 0) return "";
        if (_numerator == 0) return "0";

        long long sign = 1;
        if (_numerator < 0){
            sign *= -1;
            _numerator *= -1;
        }
        if (_denominator < 0){
            sign *= -1;
            _denominator *= -1;
        }

        string result = "";

        long long integer_part = _numerator / _denominator;
        long long float_part = _numerator % _denominator;

        do{
            result += (integer_part % 10) + 48;
            integer_part /= 10;
        } while(integer_part);
        if (sign == -1) result += '-';
        reverse(result.begin(), result.end());

        vector <long long> float_part_arr;
        map<long long, long long> modulo;
        long long cycle_index = -1;

        while(float_part && modulo.find(float_part) == modulo.end() && float_part_arr.size() < 1000){
            modulo[float_part] = float_part_arr.size();
            float_part *= 10;
            float_part_arr.push_back(float_part / _denominator);
            float_part %= _denominator;
        }

        if (float_part && modulo.find(float_part) != modulo.end()){
            cycle_index = modulo[float_part];
        }

        if (float_part_arr.size()){
            result += '.';
            if (cycle_index == -1){
                for (int i = 0; i < float_part_arr.size(); i++){
                    result += float_part_arr[i] + 48;
                }
            }
            else{
                for (int i = 0; i < cycle_index; i++){
                    result += float_part_arr[i] + 48;
                }
                result += '(';
                for (int i = cycle_index; i < float_part_arr.size(); i++){
                    result += float_part_arr[i] + 48;
                }
                result += ')';
            }
        }

        return result;
    }
};