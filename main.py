# main.py
from transformers import pipeline

# Load the dialog model
chatbot = pipeline("conversational", model="microsoft/DialoGPT-medium")

def get_response(input_text):
 response = chatbot(input_text)
 return response[0]['generated_text']

def main():
 print("Hello! I'm an AI psychologist. How can I help?")
 while True:
 user_input = input("You: ")
 if user_input.lower() in ["bye", "bye", "bye", "exit"]:
 print("Psychologist: Goodbye! I hope you have a good day.")
 break
 response = get_response(user_input)
 print("Psychologist:", response)

if __name__ == "__main__":
 main()
