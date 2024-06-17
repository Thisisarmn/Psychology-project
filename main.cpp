// main.cpp
#include "iostream"
#include "cstdlib"
#include "string"

// Function to execute Python commands and get response
std::string runPythonScript(const std::string& input_text) {
 std::string command = "python3 -c \"from transformers import pipeline; chatbot = pipeline('conversational', model='microsoft/DialoGPT-medium'); response = chatbot('" + input_text + "'); print(response[0]['generated_text'])\"";
 char buffer[128];
 std::string result = "";
 FILE* pipe = popen(command.c_str(), "r");
 if (!pipe) throw std::runtime_error("popen() failed!");
 try {
 while (fgets(buffer, sizeof buffer, pipe) != nullptr) {
 result += buffer;
 }
 } catch (...) {
 pclose(pipe);
 throw;
 }
 pclose(pipe);
 return result;
}

int main() {
 std::string user_input;
 std::cout << "Hello! I'm a psychologist AI. How can I help?" << std::endl;
 while (true) {
 std::cout << "You: ";
 std::getline(std::cin, user_input);
 if (user_input == "bye" || user_input == "bye" || user_input == "bye" || user_input == "exit") {
 std::cout << "Psychologist: Goodbye! I hope you have a good day." << std::endl;
 break;
 }
 std::string response = runPythonScript(user_input);
 std::cout << "Psychologist: " << response << std::endl;
 }
 return 0;
}
