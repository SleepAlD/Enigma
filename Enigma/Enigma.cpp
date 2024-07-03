#include <iostream>
#include <string>
#include <map>

using namespace std;

//加密轉盤 I
static int Rotor_I(int n) {

    //設定轉盤單位位移量
    map<char, int> key;
    key['a'] = 32;
    key['b'] = -5;
    key['c'] = 10;
    key['d'] = 14;
    key['e'] = -23;
    key['f'] = 21;
    key['g'] = 3;
    key['h'] = 23;
    key['i'] = -4;
    key['j'] = 32;
    key['k'] = -7;
    key['l'] = 13;
    key['m'] = 12;
    key['n'] = -17;
    key['o'] = 6;
    key['p'] = -9;
    key['q'] = -3;
    key['r'] = 14;
    key['s'] = -6;
    key['t'] = 4;
    key['u'] = -13;
    key['v'] = 22;
    key['w'] = -12;
    key['x'] = -20;
    key['y'] = 1;
    key['z'] = -11;

    //限制位移量
    if (key[n] > 26) {
        do {
            key[n] -= 26;
        } while (key[n] > 26);
    }
    else if (key[n] < -26) {
        do {
            key[n] += -26;
        } while (key[n] < -26);
    }
    return key[n];

}

//加密轉盤 II
static int Rotor_II(int n) {

    //設定轉盤單位位移量
    map<char, int> key;
    key['a'] = 12;
    key['b'] = 35;
    key['c'] = -16;
    key['d'] = 34;
    key['e'] = 33;
    key['f'] = 1;
    key['g'] = -3;
    key['h'] = 21;
    key['i'] = -7;
    key['j'] = -9;
    key['k'] = 11;
    key['l'] = -41;
    key['m'] = -12;
    key['n'] = -17;
    key['o'] = 27;
    key['p'] = 9;
    key['q'] = 13;
    key['r'] = 24;
    key['s'] = 26;
    key['t'] = -46;
    key['u'] = 13;
    key['v'] = -22;
    key['w'] = -12;
    key['x'] = 20;
    key['y'] = -11;
    key['z'] = 31;

    //限制位移量
    if (key[n] > 26) {
        do {
            key[n] -= 26;
        } while (key[n] > 26);
    }
    else if (key[n] < -26) {
        do {
            key[n] += -26;
        } while (key[n] < -26);
    }
    return key[n];

}

static string caesar_IN(string Plaintext, char key, char key2) {

    //轉盤起始位置
    int key_to_Move = int(key);
    int key_to_Move_2 = int(key2);

    //轉換大寫
    for (int i = 0; i < Plaintext.length(); i++) {

        if (Plaintext[i] >= 97 && Plaintext[i] <= 122) {
            Plaintext[i] -= 32;
        }
    }

    //執行加密
    for (int i = 0; i < Plaintext.length(); i++) {

        //確認字符範圍
        if (Plaintext[i] >= 65 && Plaintext[i]<=90) {

            //使用轉子I 進行字元替換
            Plaintext[i] += Rotor_I(key_to_Move);

            //確認字元輸出範圍
            if (Plaintext[i] > 90) {
                Plaintext[i] -= 26;
            }
            else if (Plaintext[i] < 65) {
                Plaintext[i] += 26;
            }

            //使用轉子II 進行字元替換
            Plaintext[i] += Rotor_II(key_to_Move_2);

            //確認字元輸出範圍
            if (Plaintext[i] > 90) {
                Plaintext[i] -= 26;
            }
            else if (Plaintext[i] < 65) {
                Plaintext[i] += 26;
            }
        }

        //轉盤I旋轉
        key_to_Move += 1;
        if (key_to_Move > 122) {
            key_to_Move -= 26;

            //轉盤II旋轉
            key_to_Move_2 += 1;
            if (key_to_Move_2 > 122) {
                key_to_Move_2 -= 26;
            }
        }
    }

    return Plaintext;
}

static string caesar_OUT(string Plaintext, char key, char key2) {

    //轉盤起始位置
    int key_to_Move = int(key);
    int key_to_Move_2 = int(key2);

    //轉換大寫
    for (int i = 0; i < Plaintext.length(); i++) {

        if (Plaintext[i] >= 97 && Plaintext[i] <= 122) {
            Plaintext[i] -= 32;
        }
    }

    //執行加密
    for (int i = 0; i < Plaintext.length(); i++) {

        //確認字符範圍
        if (Plaintext[i] >= 65 && Plaintext[i] <= 90) {
            //字元替換
            Plaintext[i] -= Rotor_I(key_to_Move);

            //確認字元輸出範圍
            if (Plaintext[i] > 90) {
                Plaintext[i] -= 26;
            }
            else if (Plaintext[i] < 65) {
                Plaintext[i] += 26;
            }

            //使用轉子II 進行字元替換
            Plaintext[i] -= Rotor_II(key_to_Move_2);

            //確認字元輸出範圍
            if (Plaintext[i] > 90) {
                Plaintext[i] -= 26;
            }
            else if (Plaintext[i] < 65) {
                Plaintext[i] += 26;
            }

        }

        //轉盤I旋轉
        key_to_Move += 1;
        if (key_to_Move > 122) {
            key_to_Move -= 26;

            //轉盤II旋轉
            key_to_Move_2 += 1;
            if (key_to_Move_2 > 122) {
                key_to_Move_2 -= 26;
            }
        }
    }

    return Plaintext;
}

int main()
{
 
    string text;
    char key, key2;
    bool transfrom;

    //設定加解密模式
    cout << "Check the mode to tranform( 0:encryption , 1:Decrypt ) : ";

    //確認模式是否設定成功
    if (cin >> transfrom) {

        //設定轉盤初始值
        cout << "Input the key1(a ~ z) : ";
        cin >> key;
        cout << "Input the key2(a ~ z) : ";
        cin >> key2;

        //清除cin目前緩衝區的內容
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //輸入轉換句
        cout << "Input the text : ";
        getline(cin, text);

        //加解密執行判斷
        if (transfrom == false) {

            //執行加密
            cout << endl << text << endl;
            cout << caesar_IN(text, key, key2) << endl;
        }
        else {

            //執行解密
            cout << endl << text << endl;
            cout << caesar_OUT(text, key, key2) << endl;
        }
    }
    else {
        cout << "set mode fail";
    }

    return 0;
}