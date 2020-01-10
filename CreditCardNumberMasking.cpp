#include <iostream>
#include <string>
#include <regex>
#include <boost/regex.hpp>
using namespace std;


string maskCCNumber(string aFreeText){
	string pattern = "(?:4[0-9]{12}(?:[0-9]{3})?|(?:5[1-5][0-9]{2} | 222[1-9]|22[3-9][0-9]|2[3-6][0-9]{2}|27[01][0-9]|2720)[0-9]{12}|3[47][0-9]{13}|3(?:0[0-5]|[68][0-9])[0-9]{11}|6(?:011|5[0-9]{2})[0-9]{12}|(?:2131|1800|35/d{3})/d{11})";
	static const boost::regex expr(pattern);
	return boost::regex_replace(aFreeText,expr,"****************");
}

int main()
{
	string input1 = "asdasd 4160211506302323 asdasd";
	string input2 = "4160211506302323 asdasd";
	string input3 = "asdasd 4160211506302323 ";
	string input4 = "hello";
	string input5 = "4160211506302323";
	cout<<"Input:"<<input1<<endl<<"Output:"<<maskCCNumber(input1)<<endl;
	cout<<endl;
	cout<<"Input:"<<input2<<endl<<"Output:"<<maskCCNumber(input2)<<endl;
	cout<<endl;
	cout<<"Input:"<<input3<<endl<<"Output:"<<maskCCNumber(input3)<<endl;
	cout<<endl;	
	cout<<"Input:"<<input4<<endl<<"Output:"<<maskCCNumber(input4)<<endl;
	cout<<endl;	
	cout<<"Input:"<<input5<<endl<<"Output:"<<maskCCNumber(input5)<<endl;
	return 0;
}
