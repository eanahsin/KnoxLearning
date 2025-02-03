#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to display a question and record the answer
void askQuestion(const string &question, char &answer) {
    while (true) {
        cout << question << "\nEnter your answer (A, B, C, or D): ";
        cin >> answer;
        answer = toupper(answer);

        if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D') {
            break;
        } else {
            cout << "Invalid input. Please enter A, B, C, or D.\n";
        }
    }
    cout << endl;
}

// Function to determine the dominant learning style based on counts
string determineLearningStyle(int countA, int countB, int countC, int countD) {
    if (countA >= countB && countA >= countC && countA >= countD) {
        return "Visual Learning";
    } else if (countB >= countA && countB >= countC && countB >= countD) {
        return "Auditory Learning";
    } else if (countC >= countA && countC >= countB && countC >= countD) {
        return "Reading/Writing Learning";
    } else {
        return "Kinesthetic Learning";
    }
}

// Function to display study tips based on learning style
void displayLearningTips(const string &style) {
    cout << "\nSuggested Study Techniques: \n";
    if (style == "Visual Learning") {
        cout << "- Use charts, graphs, and diagrams.\n- Color-code your notes.\n- Visualize information through mind maps.\n";
    } else if (style == "Auditory Learning") {
        cout << "- Study by listening to recordings.\n- Discuss material with others.\n- Read notes aloud to reinforce memory.\n";
    } else if (style == "Reading/Writing Learning") {
        cout << "- Summarize notes in your own words.\n- Use lists and read extensively.\n- Write down key points repeatedly.\n";
    } else if (style == "Kinesthetic Learning") {
        cout << "- Use hands-on examples and models.\n- Act out information or use physical activities.\n- Engage in practical exercises.\n";
    }
}

int main() {
    int countA = 0, countB = 0, countC = 0, countD = 0;
    vector<char> answers(10);
    string questions[] = {
        "1. When studying new material, what helps you remember it best?\n   A. Looking at charts, diagrams, or maps.\n   B. Listening to recordings or discussing the material with others.\n   C. Reading through the text or writing notes.\n   D. Doing hands-on activities or experimenting with the material.",
        "2. If you were learning a new language, what would you prefer to focus on?\n   A. Watching videos with subtitles.\n   B. Listening to native speakers or audio lessons.\n   C. Reading and writing vocabulary lists.\n   D. Practicing conversations or engaging in interactive activities.",
        "3. When giving a presentation, how do you feel most comfortable preparing?\n   A. Creating a visual slideshow with images or charts.\n   B. Practicing by saying the material out loud or with a group.\n   C. Writing down everything you want to say in detail.\n   D. Rehearsing while moving around or using props.",
        "4. What helps you stay focused during a lecture or presentation?\n   A. Watching a video or looking at visuals that go along with the content.\n   B. Listening closely to the speaker’s tone and emphasis.\n   C. Taking detailed notes or following along in a book.\n   D. Using hand gestures or taking breaks to stretch while listening.",
        "5. If you’re struggling to understand a concept, what do you usually do?\n   A. Draw a diagram or create a chart.\n   B. Talk it over with a classmate or teacher.\n   C. Read the material multiple times or write out an explanation.\n   D. Use physical objects or act it out to see how it works.",
        "6. Which of these study techniques sounds most effective to you?\n   A. Drawing mind maps or creating visual summaries.\n   B. Saying information out loud or explaining it to someone else.\n   C. Reading and rewriting notes.\n   D. Using flashcards or trying real-life examples.",
        "7. What is your favorite type of assignment?\n   A. Making a visual project, like a poster or infographic.\n   B. Giving a spoken presentation or engaging in a group discussion.\n   C. Writing an essay or report.\n   D. Conducting an experiment or completing a project that requires physical work.",
        "8. How do you prefer to learn from a textbook?\n   A. Looking at graphs, tables, and images.\n   B. Reading out loud or discussing the material with a friend.\n   C. Reading the text carefully and taking notes in the margins.\n   D. Highlighting key points, then testing yourself by doing exercises.",
        "9. When solving a problem, what approach do you take?\n   A. Draw or visualize the problem.\n   B. Talk through it, maybe even out loud.\n   C. Write out a step-by-step solution.\n   D. Try out different methods until something works.",
        "10. After attending a class, how do you review what you learned?\n   A. Look over visuals like slides or pictures taken during the class.\n   B. Discuss with a classmate or listen to a recording.\n   C. Rewrite notes or summarize the material in your own words.\n   D. Create a hands-on project or apply the material practically."
    };

    // Ask each question and record answers
    for (int i = 0; i < 10; i++) {
        askQuestion(questions[i], answers[i]);

        // Update count based on answer
        switch (answers[i]) {
            case 'A': countA++; break;
            case 'B': countB++; break;
            case 'C': countC++; break;
            case 'D': countD++; break;
        }
    }

    // Determine the dominant learning style
    string dominantStyle = determineLearningStyle(countA, countB, countC, countD);
    cout << "\nYour dominant learning style is: " << dominantStyle << endl;

    // Display summary of answers
    cout << "\nSummary of your answers: \n";
    cout << "Visual (A): " << countA << endl;
    cout << "Auditory (B): " << countB << endl;
    cout << "Reading/Writing (C): " << countC << endl;
    cout << "Kinesthetic (D): " << countD << endl;

    // Option to review and change answers
    char review;
    cout << "\nWould you like to review your answers? (y/n): ";
    cin >> review;
    review = tolower(review);

    if (review == 'y') {
        int questionNum;
        cout << "Enter the question number to change your answer (1-10) or 0 to finish: ";
        while (cin >> questionNum && questionNum != 0) {
            if (questionNum < 1 || questionNum > 10) {
                cout << "Invalid question number. Enter again (1-10 or 0 to finish): ";
                continue;
            }

            char newAnswer;
            askQuestion(questions[questionNum - 1], newAnswer);

            // Update counts by adjusting previous answer and new one
            switch (answers[questionNum - 1]) {
                case 'A': countA--; break;
                case 'B': countB--; break;
                case 'C': countC--; break;
                case 'D': countD--; break;
            }
            answers[questionNum - 1] = newAnswer;

            switch (newAnswer) {
                case 'A': countA++; break;
                case 'B': countB++; break;
                case 'C': countC++; break;
                case 'D': countD++; break;
            }

            cout << "Enter another question number to change (1-10) or 0 to finish: ";
        }
        dominantStyle = determineLearningStyle(countA, countB, countC, countD);
        cout << "\nUpdated dominant learning style: " << dominantStyle << endl;
    }

    // Display learning tips based on the dominant learning style
    displayLearningTips(dominantStyle);

    return 0;
}






