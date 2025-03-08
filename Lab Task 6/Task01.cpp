#include <iostream>
#include <string>
using namespace std;

class Message
{
    string messageContent;

public:
    Message() : messageContent("") {}
    Message(string m) : messageContent(m) {}

    void setString(const string &s) { messageContent = s; }
    string toString() const { return messageContent; }
    string getString() const { return messageContent; }  // For encoding later on, assuming that we are enconding the message, not the concatenated string, hence the original message should have a getter
};

class SMS : public Message
{
    string recipientContactNo;

public:
    SMS(string n, string m) : Message(m)
    {
        recipientContactNo = n;
    }

    void setContactNo(const string &number) { recipientContactNo = number; }
    string getContactNo() const { return recipientContactNo; }
    string toString() const
    {
        return "To: " + recipientContactNo + " | Message: " + Message ::toString();
    }
};

class Email : public Message
{
    string sender;
    string receiver;
    string subject;

public:
    Email(string s, string r, string sub, string m) : Message(m)
    {
        sender = s;
        receiver = r;
        subject = sub;
    }

    void setSender(const string &s) { sender = s; }
    void setReceiver(const string &r) { receiver = r; }
    void setSubject(const string &sub) { subject = sub; }
    string getSender() const { return sender; }
    string getReceiver() const { return receiver; }
    string getSubject() const { return subject; }
    string toString() const
    {
        return "Sender: " + sender + " | Receiver: " + receiver + " | Subject: " + subject + " | Message: " + Message ::toString();
    }
};

bool ContainsKeyword(const Message &messageObject, const string &keyword)
{
    /* Alternate longer code */
    string text = messageObject.toString();
    string word = "";

    for (int i = 0; i < text.length(); i++) {
        // If we encounter a space or punctuation, compare the word
        if (isspace(text[i]) || ispunct(text[i])) {
            if (word == keyword) {
                return true;
            }
            word = "";
        }
        else {
            word += text[i];
        }
    }

    // Check the last word (in case the string does not end with space)
    return word == keyword;
}

string EncodeMessage(const string &text)
{
    string encodedText = text;
    for (int i = 0; i < encodedText.length(); i++)
    {
        if ((encodedText[i] >= 'A' && encodedText[i] < 'Z') || (encodedText[i] >= 'a' && encodedText[i] < 'z'))
        {
            encodedText[i] += 1;
        }
        else if (encodedText[i] == 'Z')
        {
            encodedText[i] = 'A';
        }
        else if (encodedText[i] == 'z')
        {
            encodedText[i] = 'a';
        }
    }

    return encodedText;
}

int main()
{
    Message msg("Ramadan Mubarak!");
    cout << "Message: " << msg.toString() << endl << endl;

    SMS sms("0306-1234567", "Hey, how are you?");
    cout << "SMS: " << endl << sms.toString() << endl << endl;

    Email email("rayyanaamir@gmail.com", "usaidkhan@gmail.com", "Project Update", "Meeting at 3 PM");
    cout << "Email: " << endl << email.toString() << endl << endl;

    cout << "Message contains 'Eid': " << (ContainsKeyword(msg, "Eid") ? "Yes" : "No") << endl;
    cout << "SMS contains 'how': " << (ContainsKeyword(sms, "how") ? "Yes" : "No") << endl;
    cout << "Email contains 'Meeting': " << (ContainsKeyword(email, "Meeting") ? "Yes" : "No") << endl << endl;

    // Assuming that we are encoding the message only, not the concatenated string
    cout << "Encoded Message: " << EncodeMessage(msg.getString()) << endl;
    cout << "Encoded SMS: " << EncodeMessage(sms.getString()) << endl;
    cout << "Encoded Email: " << EncodeMessage(email.getString()) << endl;

    return 0;
}