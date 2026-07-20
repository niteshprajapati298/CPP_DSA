#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;
class DocumentEditor {

    public :

    vector<string>docsElement;
    string renderedDocument;
    void addText(string text){
        docsElement.push_back(text);
    }
    void addImage(string imagePath){
         docsElement.push_back(imagePath);
    }
    string renderDocument(){
        if(renderedDocument.empty()){
            string result;
            for(auto element : docsElement){
                if( element.size()>4 && (element.substr(element.size()-4)== ".jpg" || element.substr(element.size()-4)== ".png")) {
                   result += "[Image: " + element + "]" + "\n";
                }
                else {
                    result += element + "\n";
                }
            }
            renderedDocument = result; 
        }
        return renderedDocument;

    };
    void saveToFile(){
       ofstream file("../document.txt");
        if(file.is_open()){
            file << renderDocument();
            file.close();
            cout << "Document Successfully Saved to file " << endl;
        }
        else {
            cout << "Error: Unable to Save Document to File"<< endl; 
        }
       
    };
};

int main(){
    DocumentEditor editor;
    editor.addText("Hello, this is a sample document.");
    editor.addImage("photo.jpg");
    editor.addText("This text appears after the image.");

    string output = editor.renderDocument();
    cout << output;

    editor.saveToFile();
    return 0;
}