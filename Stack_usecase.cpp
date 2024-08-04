#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Define an Action structure to represent user actions.
struct Action {
  string type; // The type of action (e.g., "add", "delete")
  string data; // Data involved in the action (e.g., the text added or deleted)

  Action(string type, string data) : type(type), data(data) {}
};

class TextEditor {
private:
  stack<Action>
      actions; // Stack to keep track of actions for undo functionality

public:
  void performAction(const Action &action) {
    // Perform the action and push it onto the stack
    cout << "Performing action: " << action.type << " '" << action.data << "'"
         << endl;
    actions.push(action);
  }

  void undoAction() {
    if (actions.empty()) {
      cout << "No actions to undo." << endl;
      return;
    }

    // Pop the most recent action from the stack and undo it
    Action action = actions.top();
    actions.pop();
    cout << "Undoing action: " << action.type << " '" << action.data << "'"
         << endl;
    // Here, you would add code to actually reverse the action's effect
  }
};

int main() {
  TextEditor editor;

  // Simulate user actions
  editor.performAction(Action("add", "Hello"));
  editor.performAction(Action("add", " World"));
  editor.performAction(Action("delete", "World"));

  // Undo the last action
  editor.undoAction(); // Should undo "delete 'World'"
  editor.undoAction(); // Should undo "add ' World'"

  return 0;
}