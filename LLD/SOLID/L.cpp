// L -> Liskov substitution principle 

// i.e.,  "If S is a subtype of T, then objects of type T may be replaced with objects of type S without altering 
// any of the desirable properties of that program (correctness, task performed, etc.)."

#include<iostream>
using namespace std;

class Document {      // Document: represents the ability to open and view data
public:
    virtual void open() const = 0;
    virtual string getData() const = 0;
    virtual ~Document() = default;
};

class Editable {      // Editable: represents the capability to modify data
public:
    virtual void save(const string& newData) = 0;
    virtual ~Editable() = default; 
};


class EditableDocument : public Document, public Editable {
private:
    string data;

    string preview() const {
        return data.substr(0, min((size_t)20, data.length())) + "...";
    }

public:
    EditableDocument(const string& data) : data(data) {}

    void open() const override {
        cout << "Editable Document opened. Data: " << preview() << endl;
    }

    void save(const string& newData) override {
        data = newData;
        cout << "Document saved." << endl;
    }

    string getData() const override {
        return data;
    }
};

class ReadOnlyDocument : public Document {
private:
    string data;

    string preview() const {
        return data.substr(0, min((size_t)20, data.length())) + "...";
    }

public:
    ReadOnlyDocument(const string& data) : data(data) {}

    void open() const override {
        cout << "Read-Only Document opened. Data: " << preview() << endl;
    }

    string getData() const override {
        return data;
    }
};

class DocumentProcessor {
public:
    void process(const Document* doc) const {
        doc->open();
        cout << "Document processed.." << endl;
    }

    void processAndSave(Document* doc, EditableDocument* editabledoc, const string& additionalData) const {
        if (!doc || !editabledoc) {
            throw invalid_argument("Document is not editable.");
        }

        doc->open();
        string currData = doc->getData();
        string newData = currData + " | Processed: " + additionalData;
        editabledoc->save(newData);
        cout << "Editable document processed and saved." << endl;
    }
};


void demoL(){
    EditableDocument editable("Draft proposal for research on AI.");
    ReadOnlyDocument readOnly("Top secret strategy.");
    
    DocumentProcessor processor;

    cout << "---Processing Editable Document ---" << endl;
    processor.processAndSave(&editable, &editable, "Reviewed by Rishi");

    cout << "\n--- Processing Read-only Document" << endl;
    processor.process(&readOnly);
}