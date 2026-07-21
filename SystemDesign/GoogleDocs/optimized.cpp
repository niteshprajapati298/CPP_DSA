#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class DocumentElement {
public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement {
    string text;
public:
    TextElement(string t) {
        this->text = t;
    }
    string render() override {
        return "<p>" + text + "</p>";
    }
};

class ImageElement : public DocumentElement {
    string imagePath;
public:
    ImageElement(string path) {
        this->imagePath = path;
    }
    string render() override {
        return "<img src='" + imagePath + "' />";
    }
};

class NewLineElement : public DocumentElement {
public:
    string render() override {
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement {
public:
    string render() override {
        return "\t";
    }
};

class Document {
    vector<DocumentElement*> elements;

public:
    void addElement(DocumentElement* element) {
        elements.push_back(element);
    }

    string renderDocument() {
        string result = "";
        for (auto element : elements) {
            result += element->render();
        }
        return result;
    }
};

class Persistence {
public:
    virtual void save(const string& data) = 0;
};

class FilePersistence : public Persistence {
public:
    void save(const string& data) override {
        ofstream file("../document.txt");
        if (file.is_open()) {
            file << data;
            file.close();
            cout << "Document saved successfully" << endl;
        } else {
            cout << "Unable to open file" << endl;
        }
    }
};

class DatabasePersistence : public Persistence {
public:
    void save(const string& data) override {
        (void)data;
        cout << "Document saved to database successfully" << endl;
    }
};

class DocumentEditor {
    Document* document;
    Persistence* persistence;
    string renderedDocument;
public:
    DocumentEditor(Document* doc, Persistence* pers) {
        this->document = doc;
        this->persistence = pers;
    }

    void saveDocument() {
        renderedDocument = document->renderDocument();
        persistence->save(renderedDocument);
    }

    void addText(string text) {
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath) {
        document->addElement(new ImageElement(imagePath));
    }

    void addNewLine() {
        document->addElement(new NewLineElement());
    }

    void addTabSpace() {
        document->addElement(new TabSpaceElement());
    }

    string render() {
        if (renderedDocument.empty()) {
            renderedDocument = document->renderDocument();
        }
        return renderedDocument;
    }

    void saveToFile() {
        renderedDocument = document->renderDocument();
        persistence->save(renderedDocument);
    }
};

int main() {
    Document doc;
    Persistence* persistence = new FilePersistence();
    // DocumentEditor editor(&doc, persistence);
    DocumentEditor *editor = new DocumentEditor(&doc, persistence);

    editor.addText("Hello, World!");
    editor.addNewLine();
    editor.addText("This is a richer document example.");
    editor.addTabSpace();
    editor.addImage("image.jpg");
    editor.addNewLine();
    editor.addText("Saved using the persistence layer.");

    cout << editor.render() << endl;
    editor.saveDocument();

    delete persistence;
    delete editor;
    return 0;
}