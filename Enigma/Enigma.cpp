#include <iostream>
#include <stdio.h>
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
            key[n] += 26;
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
            key[n] += 26;
        } while (key[n] < -26);
    }

    return key[n];

}

//加密轉盤 III
static int Rotor_III(int n) {

    //設定轉盤單位位移量
    map<char, int> key;
    key['a'] = 14;
    key['b'] = 3;
    key['c'] = 25;
    key['d'] = 40;
    key['e'] = -6;
    key['f'] = -1;
    key['g'] = -11;
    key['h'] = 23;
    key['i'] = 21;
    key['j'] = -52;
    key['k'] = -14;
    key['l'] = 24;
    key['m'] = -36;
    key['n'] = -13;
    key['o'] = 43;
    key['p'] = 52;
    key['q'] = 66;
    key['r'] = -4;
    key['s'] = 75;
    key['t'] = -7;
    key['u'] = -52;
    key['v'] = -14;
    key['w'] = 39;
    key['x'] = -9;
    key['y'] = -41;
    key['z'] = -31;

    //限制位移量
    if (key[n] > 26) {
        do {
            key[n] -= 26;
        } while (key[n] > 26);
    }
    else if (key[n] < -26) {
        do {
            key[n] += 26;
        } while (key[n] < -26);
    }
    return key[n];

}

//加密轉盤 IV
static int Rotor_IV(int n) {

    //設定轉盤單位位移量
    map<char, int> key;
    key['a'] = -14;
    key['b'] = 23;
    key['c'] = 10;
    key['d'] = -40;
    key['e'] = -16;
    key['f'] = -53;
    key['g'] = 11;
    key['h'] = 3;
    key['i'] = 21;
    key['j'] = -50;
    key['k'] = -14;
    key['l'] = -4;
    key['m'] = -6;
    key['n'] = 3;
    key['o'] = -43;
    key['p'] = -52;
    key['q'] = 26;
    key['r'] = 10;
    key['s'] = 15;
    key['t'] = -27;
    key['u'] = 52;
    key['v'] = -4;
    key['w'] = 39;
    key['x'] = 19;
    key['y'] = -1;
    key['z'] = 1;

    //限制位移量
    if (key[n] > 26) {
        do {
            key[n] -= 26;
        } while (key[n] > 26);
    }
    else if (key[n] < -26) {
        do {
            key[n] += 26;
        } while (key[n] < -26);
    }
    return key[n];

}

//反射器
static int Reflector(int key) {

    if (key >= 'a' && key <= 'z') {

        key += 13;
        if (key > 122) {
            key -= 26;
        }
    }

    return key;
}

//確認字元輸出範圍
static char check_Range(char Plaintext) {

    if (Plaintext > 90) {
        Plaintext -= 26;
    }
    else if (Plaintext < 65) {
        Plaintext += 26;
    }

    return Plaintext;
}

//字元交換
static char plugboard_switch(char plug1, char plug2) {
    char temp;
    temp = plug1;
    plug1 = plug2;
    plug2 = temp;

    return plug1;
}

//加密區域
static string caesar_IN(string Plaintext, char key, char key2, char key3, char key4, char plug[2]) {

    //轉盤起始位置
    int key_to_Move = int(key);
    int key_to_Move_2 = int(key2);
    int key_to_Move_3 = int(key3);
    int key_to_Move_4 = int(key4);



    //轉換大寫
    for (int i = 0; i < Plaintext.length(); i++) {

        if (Plaintext[i] == plug[0]) {
            Plaintext[i] = plugboard_switch(Plaintext[i], plug[1]);
        }
        else if (Plaintext[i] == plug[1]) {
            Plaintext[i] = plugboard_switch(Plaintext[i], plug[0]);
        }

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
            Plaintext[i] = check_Range(Plaintext[i]);
 
            //使用轉子II 進行字元替換
            Plaintext[i] += Rotor_II(key_to_Move_2);
            Plaintext[i] = check_Range(Plaintext[i]);
           
            //使用轉子III 進行字元替換
            Plaintext[i] += Rotor_III(key_to_Move_3);
            Plaintext[i] = check_Range(Plaintext[i]);
            
            //使用轉子IV 進行字元替換
            Plaintext[i] += Rotor_IV(key_to_Move_4);
            Plaintext[i] = check_Range(Plaintext[i]);
            
            //使用反射器進行第二階段

            //使用轉子IV 進行字元替換
            Plaintext[i] += Rotor_IV(Reflector(key_to_Move_4));
            Plaintext[i] = check_Range(Plaintext[i]);
            
            //使用轉子III 進行字元替換
            Plaintext[i] += Rotor_III(Reflector(key_to_Move_3));
            Plaintext[i] = check_Range(Plaintext[i]);
          
            //使用轉子II 進行字元替換
            Plaintext[i] += Rotor_II(Reflector(key_to_Move_2));
            Plaintext[i] = check_Range(Plaintext[i]);
            
            //使用轉子I 進行字元替換
            Plaintext[i] += Rotor_I(Reflector(key_to_Move));
            Plaintext[i] = check_Range(Plaintext[i]);
            
        }

        //轉盤I旋轉
        key_to_Move += 1;
        if (key_to_Move > 122) {
            key_to_Move -= 26;

            //轉盤II旋轉
            key_to_Move_2 += 1;
            if (key_to_Move_2 > 122) {
                key_to_Move_2 -= 26;

                //轉盤III旋轉
                key_to_Move_3 += 1;
                if (key_to_Move_3 > 122) {
                    key_to_Move_3 -= 26;

                    //轉盤IV旋轉
                    key_to_Move_4 += 1;
                    if (key_to_Move_4 > 122) {
                        key_to_Move_4 -= 26;
                    }
                }
            }
        }
    }

    return Plaintext;
}

//解密區域
static string caesar_OUT(string Plaintext, char key, char key2, char key3, char key4, char plug[2]) {

    //轉盤起始位置
    int key_to_Move = int(key);
    int key_to_Move_2 = int(key2);
    int key_to_Move_3 = int(key3);
    int key_to_Move_4 = int(key4);

    //轉換大寫
    for (int i = 0; i < Plaintext.length(); i++) {

        if (Plaintext[i] >= 97 && Plaintext[i] <= 122) {
            Plaintext[i] -= 32;
        }
    }

    //執行解密
    for (int i = 0; i < Plaintext.length(); i++) {

        //確認字符範圍
        if (Plaintext[i] >= 65 && Plaintext[i] <= 90) {

            //使用轉子I 進行字元替換
            Plaintext[i] -= Rotor_I(key_to_Move);
            Plaintext[i] = check_Range(Plaintext[i]);

            //使用轉子II 進行字元替換
            Plaintext[i] -= Rotor_II(key_to_Move_2);
            Plaintext[i] = check_Range(Plaintext[i]);

            //使用轉子III 進行字元替換
            Plaintext[i] -= Rotor_III(key_to_Move_3);
            Plaintext[i] = check_Range(Plaintext[i]);

            //使用轉子IV 進行字元替換
            Plaintext[i] -= Rotor_IV(key_to_Move_4);
            Plaintext[i] = check_Range(Plaintext[i]);

            //使用反射器進行第二階段

            //使用轉子IV 進行字元替換
            Plaintext[i] -= Rotor_IV(Reflector(key_to_Move_4));
            Plaintext[i] = check_Range(Plaintext[i]);

            //使用轉子III 進行字元替換
            Plaintext[i] -= Rotor_III(Reflector(key_to_Move_3));
            Plaintext[i] = check_Range(Plaintext[i]);

            //使用轉子II 進行字元替換
            Plaintext[i] -= Rotor_II(Reflector(key_to_Move_2));
            Plaintext[i] = check_Range(Plaintext[i]);

            //使用轉子I 進行字元替換
            Plaintext[i] -= Rotor_I(Reflector(key_to_Move));
            Plaintext[i] = check_Range(Plaintext[i]);

        }

        if (Plaintext[i] == (plug[0] - 32)) {
            Plaintext[i] = plugboard_switch(Plaintext[i], (plug[1]-32));
        }
        else if (Plaintext[i] == (plug[1] - 32)) {
            Plaintext[i] = plugboard_switch(Plaintext[i], (plug[0]-32));
        }


        //轉盤I旋轉
        key_to_Move += 1;
        if (key_to_Move > 122) {
            key_to_Move -= 26;

            //轉盤II旋轉
            key_to_Move_2 += 1;
            if (key_to_Move_2 > 122) {
                key_to_Move_2 -= 26;

                //轉盤III旋轉
                key_to_Move_3 += 1;
                if (key_to_Move_3 > 122) {
                    key_to_Move_3 -= 26;

                    //轉盤IV旋轉
                    key_to_Move_4 += 1;
                    if (key_to_Move_4 > 122) {
                        key_to_Move_4 -= 26;
                    }
                }
            }
        }
    }

    return Plaintext;
}

int main() {

    string text;
    char key, key2, key3, key4, check_continue;
    char plug[2];
    bool transfrom;

    do {

        system("cls");

        // 設定加解密模式
        cout << "Check the mode to transform (0: encryption, 1: Decrypt): ";

        // 確認模式是否設定成功
        if (cin >> transfrom) {

            // 設定加密轉盤初始值
            cout << "Input the key (4 char): ";
            cin >> key;
            cin >> key2;
            cin >> key3;
            cin >> key4;

            // 設定接線板數值
            cout << "Two char on plugboard:";
            cin >> plug[0] >> plug[1];

            // 清除 cin 目前緩衝區的內容
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // 輸入轉換句
            cout << "Input the text: ";
            getline(cin, text);

            // 加解密執行判斷
            if (transfrom == false) {
                // 執行加密
                cout << endl << text << endl;
                cout << endl << caesar_IN(text, key, key2, key3, key4, plug) << endl;
            }
            else {
                // 執行解密
                cout << endl << text << endl;
                cout << endl << caesar_OUT(text, key, key2, key3, key4, plug) << endl;
            }
        }
        else {
            cout << "set mode fail";
        }

        cout << endl << "Continue executing the application (y/n) : ";
        cin >> check_continue;

    } while (check_continue == 'y');

    cout << endl << "-----------------------------------------" << endl;
    cout << endl << "Input ENTER to continue" << endl;
    cin.get();
    return 0;
}