/*!****************************************************************************************
 *      Convert the file name of the Japanese character code (U+F6F7 ~) 
 *      of the Unicode completion plan to unicode Japanese character code (U+3041 ~)
 *
 *      Copyright (c) 2019 ,mojo
 *****************************************************************************************/  

#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <map>
#include <filesystem>

using namespace std;
namespace fs=std::filesystem;

const string Ver="Ver 0.1.1";
void Help()
{
    cout<<"Convert the file name of the Japanese character code (U+F6F7 ~) of the Unicode completion plan to unicode Japanese character code (U+3041 ~)"<<endl;
    cout<<"Usage::ConvUAO directory"<<endl;
}
int main(int argc, char **argv) 
{
    const vector<pair<string,string> >big5JP2unicode=
    {
        {"","ぁ"},
        {"","あ"},
        {"","ぃ"},
        {"","い"},
        {"","ぅ"},
        {"","う"},
        {"","ぇ"},
        {"","え"},
        {"","ぉ"},
        {"","お"},
        {"","か"},
        {"","が"},
        {"","き"},
        {"","ぎ"},
        {"","く"},
        {"","ぐ"},
        {"","け"},
        {"","げ"},
        {"","こ"},
        {"","ご"},
        {"","さ"},
        {"","ざ"},
        {"","し"},
        {"","じ"},
        {"","す"},
        {"","ず"},
        {"","せ"},
        {"","ぜ"},
        {"","そ"},
        {"","ぞ"},
        {"","た"},
        {"","だ"},
        {"","ち"},
        {"","ぢ"},
        {"","っ"},
        {"","つ"},
        {"","づ"},
        {"","て"},
        {"","で"},
        {"","と"},
        {"","ど"},
        {"","な"},
        {"","に"},
        {"","ぬ"},
        {"","ね"},
        {"","の"},
        {"","は"},
        {"","ば"},
        {"","ぱ"},
        {"","ひ"},
        {"","び"},
        {"","ぴ"},
        {"","ふ"},
        {"","ぶ"},
        {"","ぷ"},
        {"","へ"},
        {"","べ"},
        {"","ぺ"},
        {"","ほ"},
        {"","ぼ"},
        {"","ぽ"},
        {"","ま"},
        {"","み"},
        {"","む"},
        {"","め"},
        {"","も"},
        {"","ゃ"},
        {"","や"},
        {"","ゅ"},
        {"","ゆ"},
        {"","ょ"},
        {"","よ"},
        {"","ら"},
        {"","り"},
        {"","る"},
        {"","れ"},
        {"","ろ"},
        {"","ゎ"},
        {"","わ"},
        {"","ゐ"},
        {"","ゑ"},
        {"","を"},
        {"","ん"},
        ///////////////////////
        {"","ァ"},
        {"","ア"},
        {"","ィ"},
        {"","イ"},
        {"","ゥ"},
        {"","ウ"},
        {"","ェ"},
        {"","エ"},
        {"","ォ"},
        {"","オ"},
        {"","カ"},
        {"","ガ"},
        {"","キ"},
        {"","ギ"},
        {"","ク"},
        {"","グ"},
        {"","ケ"},
        {"","ゲ"},
        {"","コ"},
        {"","ゴ"},
        {"","サ"},
        {"","ザ"},
        {"","シ"},
        {"","ジ"},
        {"","ス"},
        {"","ズ"},
        {"","セ"},
        {"","ゼ"},
        {"","ソ"},
        {"","ゾ"},
        {"","タ"},
        {"","ダ"},
        {"","チ"},
        {"","ヂ"},
        {"","ッ"},
        {"","ツ"},
        {"","ヅ"},
        {"","テ"},
        {"","デ"},
        {"","ト"},
        {"","ド"},
        {"","ナ"},
        {"","ニ"},
        {"","ヌ"},
        {"","ネ"},
        {"","ノ"},
        {"","ハ"},
        {"","バ"},
        {"","パ"},
        {"","ヒ"},
        {"","ビ"},
        {"","ピ"},
        {"","フ"},
        {"","ブ"},
        {"","プ"},
        {"","ヘ"},
        {"","ベ"},
        {"","ペ"},
        {"","ホ"},
        {"","ボ"},
        {"","ポ"},
        {"","マ"},
        {"","ミ"},
        {"","ム"},
        {"","メ"},
        {"","モ"},
        {"","ャ"},
        {"","ヤ"},
        {"","ュ"},
        {"","ユ"},
        {"","ョ"},
        {"","ヨ"},
        {"","ラ"},
        {"","リ"},
        {"","ル"},
        {"","レ"},
        {"","ロ"},
        {"","ヮ"},
        {"","ワ"},
        {"","ヰ"},
        {"","ヱ"},
        {"","ヲ"},
        {"","ン"},
        {"","ヴ"},
        {"","ヵ"},
        {"","ヶ"},        
    };
    
    cout << "Hello, ConvUAO! "<<Ver << endl;
    if(argc!=2)
    {
        Help();
        return -1;
    }
    
    string dir=argv[1];
    bool bRenameDir=false;
    do
    {
        bRenameDir=false;
        fs:: recursive_directory_iterator d(dir);
        for(auto &iter:d)
        {
            fs::path p(iter);
            string filename=p.filename();
            bool bRename=false;
    
            for(auto &k:big5JP2unicode)
            {
                bool bFind=true;
                do
                {
                    bFind=false;
                    std::size_t pos=filename.find(k.first);
                    if(pos!=string::npos)
                    {
                        filename.replace(pos,k.first.length(),k.second);
                        bRename=true;
                        bFind=true;
                    }
                }while(bFind);
            }
            
            if(bRename)
            {
                auto old=p;
                p.replace_filename(filename);
                rename(old,p);
                cout<<"rename"<<old<<" -->    "<<filename<<endl;
                
                if(is_directory(p))
                {
                    bRenameDir=true;
                    break;
                }
            }
        }
    }while(bRenameDir);
 
    return 0;
}
