// D -> Dependency Inversion Principle 

// High-level modules should not depend on low-level modules. Both should depend on abstractions (e.g., interfaces).
// Abstractions should not depend on details. Details (concrete implementations) should depend on abstractions.


// #include<iostream>
// using namespace std;

// class GmailClient {
// public:
//     void sendGmail(const string& toAddress, const string& subjectLine, const string& emailBody) {
//         cout << "Connecting to Gmail SMTP server..." << endl;
//         cout << "Sending email via Gmail to: " << toAddress << endl;
//         cout << "Subject: " << subjectLine << endl;
//         cout << "Body: " << emailBody << endl;
//         // ... actual Gmail API interaction logic ...
//         cout << "Gmail email sent successfully!" << endl;
//     }
// };


// class EmailService {
// private:
//     GmailClient gmailClient;

// public:
//     void sendWelcomeEmail(const string& userEmail, const string& userName) {
//         string subject = "Welcome, " + userName + "!";
//         string body = "Thanks for signing up to our awesome platform. We're glad to have you!";
//         gmailClient.sendGmail(userEmail, subject, body);
//     }

//     void sendPasswordResetEmail(const string& userEmail) {
//         string subject = "Reset Your Password";
//         string body = "Please click the link below to reset your password...";
//         gmailClient.sendGmail(userEmail, subject, body);
//     }
// };


// ................................. Now lets use the Dependency Inversion Principle .........................................


#include<iostream>
#include<memory>
using namespace std;

class EmailClient {
public:
    virtual void sendEmail(const string& to, const string& subject, const string& body) = 0;
    virtual ~EmailClient() = default;
};

class GmailClientImpl : public EmailClient {
public:
    void sendEmail(const string& to, const string& subject, const string& body) override {
        cout << "Connecting to Gmail SMTP server..." << endl;
        cout << "Sending email via gmail to - " << to << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
        cout << "Gmail email send successfully" << endl;
    }
};

class OutlookClientImpl : public EmailClient {
public:
    void sendEmail(const string& to, const string& subject, const string& body) override {
        cout << "Connection to Outlook Exchange server..." << endl;
        cout << "Sending email via Outlook to - " << to << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
        cout << "Outlook email send successfully" << endl;
    }
};


class EmailService {
private:
    shared_ptr<EmailClient> emailClient;

public:
    EmailService(shared_ptr<EmailClient> client) : emailClient(move(client)) {}

    void sendWelcomeEmail(const string& userEmail, const string& userName) {
        string subject = "Welcome, " + userName + "!";
        string body = "Thanks for signing up to our awesome platform. We're glad to have you!";
        emailClient->sendEmail(userEmail, subject, body);
    }

    void sendPasswordResetEmail(const string& userEmail) {
        string subject = "Reset your password";
        string body = "Please click the link below to reset your password...";
        emailClient->sendEmail(userEmail, subject, body);
    }
};

int main() {
    cout << "--- Using Gmail ---" << endl;
    shared_ptr<EmailClient> gmail = make_shared<GmailClientImpl>();
    EmailService gmailService(gmail);
    gmailService.sendWelcomeEmail("test@example.com", "Welcome to SOLID principles!");

    cout << "\n--- Using Outlook ---" << endl;
    shared_ptr<EmailClient> outlook = make_shared<OutlookClientImpl>();
    EmailService outlookService(outlook);
    outlookService.sendWelcomeEmail("test@example.com", "Welcome to SOLID principles!");

    return 0;
}