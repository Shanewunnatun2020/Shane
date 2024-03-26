#include <iostream>
using namespace std;

class Shane
{
public:
    string plans[3] = {"Beginner    (3 sessions per week)", "Intermediate(3 sessions per week)", "Advanced    (2 sessions per week)"};
    string BeginnerPoses[30][2] = {
        {"Standing Pose", "Downward Facing Dog"},
        {"Standing Pose", "Mountain Pose"},
        {"Standing Pose", "Warrior Pose"},
        {"Standing Pose", "Triangle Pose"},
        {"Balancing Pose", "Low Lunge"},
        {"Balancing Pose", "Tress Pose"},
        {"Balancing Pose", "Plank Pose"},
        {"Balancing Pose", "Bridge Pose"},
        {"Seat Pose", "Staff Pose"},
        {"Backend Pose", "Cobbler's Pose"},
        {"Backend Pose", "Happy Baby Pose"}};

    string IntermediatePoses[30][2] = {
        {"Standing Pose", "Archer Pose"},
        {"Standing Pose", "Dolphin Pose"},
        {"Standing Pose", "Frog Pose"},
        {"Standing Pose", "Fallen Triangle"},
        {"Balancing Pose", "Big Toe Pose"},
        {"Balancing Pose", "Lion Pose"},
        {"Balancing Pose", "Airplane Pose"},
        {"Balancing Pose", "Side Lunge"},
        {"Seated Pose", "Side Reclining"},
        {"Backend Pose", "Bird Dog Pose"},
    };

    int prices[3] = {25000, 35000, 50000};
    int TuitionPrices[2] = {15000, 17000};
    void displayWelcome();
    void menu();
    bool validateAdminCredentials(const string &enteredUsername, const string &enteredPassword);
};

class admin : public Shane
{
private:
public:
    admin()
    {
        cout << "1. View Plans\n";
        cout << "2. View Beginner Yoga Poses\n";
        cout << "3. View Intermediate Yoga Poses\n";
        cout << "4. View Tuition Prices\n";
        cout << "5. Change Plan Prices\n";
        cout << "6. Change Beginner Yoga Poses\n";
        cout << "7. Add a Beginner Yoga Pose\n";
        cout << "8. Change Intermediate Yoga Poses\n";
        cout << "9. Add an Intermediate Yoga Pose\n";
        cout << "10. Change Tuition Prices\n";
    }
    void viewPlans(Shane &Shaneclub);
    void viewBeginnerPoses(Shane &Shaneclub);
    void viewIntermediatePoses(Shane &Shaneclub);
    void viewTuitionPrices(Shane &Shaneclub);
    void modifyPlanPrice(Shane &Shaneclub);
    void modifyBeginnerPoses(Shane &Shaneclub);
    void addBeginnerPose(Shane &Shaneclub);
    void modifyIntermediatePoses(Shane &Shaneclub);
    void addIntermediatePoses(Shane &Shaneclub);
    void modifyTuitionPrices(Shane &Shaneclub);
};

class athlete : public Shane
{
private:
public:
    string name, plan, tuition;
    int weight, totalCost = 0;

    void athleteMenu();
    void displayVoucher(int passedPoses, int coachHour, int priceCell, int discount, int tutionPriceCell, athlete athletes[], Shane Shaneclub);
    void view();
    void deleteAthlete(athlete athletes[]);
    void quickSort(athlete athletes[], int start, int end);
};

int cell = 0;

int main()
{
    athlete athletes[69];
    athlete a1;

    athletes[cell].name = "Htike";
    athletes[cell].plan = "Beginner";
    athletes[cell].weight = 100;
    athletes[cell].tuition = "Offline";
    athletes[cell].totalCost = 150000;
    cell++;

    athletes[cell].name = "Matthew";
    athletes[cell].plan = "Advanced";
    athletes[cell].weight = 50;
    athletes[cell].tuition = "Online";
    athletes[cell].totalCost = 250000;
    cell++;

    athletes[cell].name = "Sai";
    athletes[cell].plan = "Advanced";
    athletes[cell].weight = 75;
    athletes[cell].tuition = "Offline";
    athletes[cell].totalCost = 288000;
    cell++;

    athletes[cell].name = "Linn";
    athletes[cell].plan = "Intermediate";
    athletes[cell].weight = 69;
    athletes[cell].tuition = "Online";
    athletes[cell].totalCost = 215000;
    cell++;

    athletes[cell].name = "Mattoo";
    athletes[cell].plan = "Beginner";
    athletes[cell].weight = 120;
    athletes[cell].tuition = "Offline";
    athletes[cell].totalCost = 125000;
    cell++;

    athletes[cell].name = "Ko Sai";
    athletes[cell].plan = "Intermediate";
    athletes[cell].weight = 95;
    athletes[cell].tuition = "Offline";
    athletes[cell].totalCost = 195000;
    cell++;

    Shane Shaneclub;
    Shaneclub.displayWelcome();
    Shaneclub.menu();

    char op;
    cin >> op;

    if (op == 'A' || op == 'a')
    {
        string username, password;

        cout << "Enter admin username:";
        cin >> username;
        cout << "Enter admin password:";
        cin >> password;
        if (Shaneclub.validateAdminCredentials(username, password))
        {
            cout << "Login successful!\n";
            char ch = 'y';
            do
            {
                admin ad1;
                int op;
                cin >> op;

                if (op == 1)
                {
                    ad1.viewPlans(Shaneclub);
                }

                else if (op == 2)
                {
                    ad1.viewBeginnerPoses(Shaneclub);
                }
                else if (op == 3)
                {
                    ad1.viewIntermediatePoses(Shaneclub);
                }
                else if (op == 4)
                {
                    ad1.viewTuitionPrices(Shaneclub);
                }
                else if (op == 5)
                {
                    ad1.modifyPlanPrice(Shaneclub);
                }

                else if (op == 6)
                {
                    ad1.modifyBeginnerPoses(Shaneclub);
                }
                else if (op == 7)
                {
                    ad1.addBeginnerPose(Shaneclub);
                }
                else if (op == 8)
                {
                    ad1.modifyIntermediatePoses(Shaneclub);
                }
                else if (op == 9)
                {
                    ad1.addIntermediatePoses(Shaneclub);
                }
                else if (op == 10)
                {
                    ad1.modifyTuitionPrices(Shaneclub);
                }
                else
                {
                    cout << "Invalid CHoice!!!\n";
                }

                cout << "Do you want to continue(y/n)?";
                cin >> ch;
            } while (ch == 'y');
        }
        else
        {
            cout << "Incorrect username or password. Try again!\n";
            Shaneclub.menu(); // Go back to the menu if login fails
        }
    }
    else if (op == 'B' || op == 'b')
    {
        char ch = 'y';
        do
        {
            int op, numCoachSession, passedPoses, discount, coachHour, tutionPriceCell;
            a1.athleteMenu();
            cin >> op;

            if (op == 1)
            {
                cout << "Name\t\tPlan\t\tWeight\t\tTuition\t\tTotalCost\n";
                for (int i = 0; i < cell; i++)
                {
                    athletes[i].view();
                }
            }
            else if (op == 2)
            {
                int priceCell;
                cout << "Enter athlete name:";
                cin.ignore();
                getline(cin, athletes[cell].name);

                cout << "Plan\t\t\t\t\t\tPrices\n";
                for (int i = 0; i < 3; i++)
                {
                    cout << Shaneclub.plans[i] << "\t\t" << Shaneclub.prices[i] << endl;
                }

                cout << "Enter training plan:\n";
                cin >> athletes[cell].plan;

                if (athletes[cell].plan == "Beginner" || athletes[cell].plan == "beginner")
                {
                    cout << "You chose beginner plan which is 25000 kyats per week.\n";
                    priceCell = 0;
                }
                else if (athletes[cell].plan == "Intermediate" || athletes[cell].plan == "intermediate")
                {
                    cout << "You chose intermediate plan which is 35000 kyats per week.\n";
                    priceCell = 1;
                    cout << "How many yoga pose have you passed?\n";
                    cout << "\t10 Yoga Beginner Poses\n";
                    cout << "Yoga Pose Type\t\tYoga Pose Name\n";
                    for (int i = 0; i < 11; i++)
                    {
                        for (int j = 0; j < 2; j++)
                        {
                            cout << Shaneclub.BeginnerPoses[i][j] << "\t\t";
                        }
                        cout << endl;
                    }
                    cin >> passedPoses;
                }
                else if (athletes[cell].plan == "Advanced" || athletes[cell].plan == "Advanced")
                {
                    cout << "You chose intermediate plan which is 50000 kyats per week.\n";
                    priceCell = 2;
                    cout << "How many yoga pose have you passed?\n";
                    cout << "\t10 Yoga Intermediate Poses\n";
                    cout << "Yoga Pose Type\t\tYoga Pose Name\n";
                    for (int i = 0; i < 10; i++)
                    {
                        for (int j = 0; j < 2; j++)
                        {
                            cout << Shaneclub.IntermediatePoses[i][j] << "\t\t";
                        }
                        cout << endl;
                    }
                    cin >> passedPoses;
                }
                else
                {
                    cout << "Invalid Choice!!";
                }

                discount = Shaneclub.prices[priceCell] * passedPoses / 100;
                athletes[cell].totalCost += (Shaneclub.prices[priceCell] - discount) * 4;
                cout << discount << "," << athletes[cell].totalCost << endl;

                cout << "Enter weight in kilograms(kg)";
                cin >> athletes[cell].weight;
                cout << "Do you want private coaching?\n";
                cout << "1. Online Private Tuition (" << Shaneclub.TuitionPrices[0] << "kyats per session)\n";
                cout << "2. Offline Private Tuition (" << Shaneclub.TuitionPrices[1] << "kyats per session)\n";
                cout << "0. No private tuition\n";
                cin >> op;

                switch (op)
                {
                case 1:
                    athletes[cell].tuition = "Online";
                    tutionPriceCell = 0;
                    cout << "How many hours of online private coaching do you want in a week?(maximum 5)";
                    cin >> coachHour;

                    if (coachHour > 5)
                    {
                        cout << "Maximum coaching hour is 5 hours. Please try again.";
                    }

                    athletes[cell].totalCost += coachHour * Shaneclub.TuitionPrices[tutionPriceCell];
                    break;

                case 2:
                    athletes[cell].tuition = "Offline";
                    tutionPriceCell = 1;
                    cout << "How many hours of offline private coaching do you want in a week?(maximum 5)";
                    cin >> coachHour;

                    if (coachHour > 5)
                    {
                        cout << "Maximum coaching hour is 5 hours. Please try again.";
                    }
                    athletes[cell].totalCost += coachHour * Shaneclub.TuitionPrices[tutionPriceCell];
                    break;

                case 0:
                    cout << "No private tuition selected.";
                    athletes[cell].tuition = "None";
                    break;

                default:
                    cout << "Invalid Choice. Please try again!";
                    break;
                }

                a1.displayVoucher(passedPoses, coachHour, priceCell, discount, tutionPriceCell, athletes, Shaneclub);
                cell++;
            }

            else if (op == 3)
            {
                a1.deleteAthlete(athletes);
            }

            else if (op == 4)
            {
                a1.quickSort(athletes, 0, cell - 1);
                for (int i = 0; i < cell; i++)
                {
                    athletes[i].view();
                }
            }
            else if (op == 0)
            {
                cout << "Exiting...";
            }
            else
            {
                cout << "Invalid choice!";
            }
            cout << "Do u want to continue?(y/n)";
            cin >> ch;
        } while (ch == 'y');
    }
    else if (op == 0)
    {
        cout << "Exiting.....";
    }
    else
    {
        cout << "Invalid Choice! Please try again!";
    }
}
void Shane::displayWelcome()
{
    system("pause");
    system("cls");
}

void Shane::menu()
{
    cout << "Login in as:\n";
    cout << "A. Admin\n";
    cout << "B. Customer\n";
    cout << "0. Exit\n";
}

bool Shane::validateAdminCredentials(const string &enteredUsername, const string &enteredPassword)
{
    const string adminUsername = "admin";
    const string adminPassword = "admin123";

    return (enteredUsername == adminUsername && enteredPassword == adminPassword);
}

void athlete::athleteMenu()
{
    cout << "Welcome Athlete. This is athlete menu!\n";
    cout << "1. View registered atheletes\n";
    cout << "2. New athlete registeration\n";
    cout << "3. Delete athlete Info\n";
    cout << "4. Sort By weight\n";
    cout << "0. Exit\n";
}

void athlete::displayVoucher(int passedPoses, int coachHour, int priceCell, int discount, int tutionPriceCell, athlete athletes[], Shane Shaneclub)
{

    cout << "\n-----------------------------------------------------------------------\n";
    cout << "                        Voucher For a month\n";
    cout << "-----------------------------------------------------------------------\n";
    cout << "Name = " << athletes[cell].name << endl;
    cout << "Plan = " << athletes[cell].plan << endl;
    cout << "Weight = " << athletes[cell].weight << endl;
    cout << "Passed Yoga Poses = " << passedPoses << endl;
    cout << "Tuition = " << athletes[cell].tuition << " coaching" << endl;
    cout << "Sessions = " << coachHour << endl;
    cout << "Plan cost = " << Shaneclub.prices[priceCell] * 4 << endl;
    cout << "Discount = " << discount * 4 << endl;
    cout << "Tuition cost = " << coachHour * Shaneclub.TuitionPrices[tutionPriceCell] << endl;
    cout << "-----------------------------------------------------------------------\n";
    cout << "Total\t\t\t" << athletes[cell].totalCost << endl;
    cout << endl;
    cout << endl;
    system("pause");
}

void athlete::view()
{
    cout << name << "\t\t" << plan << "\t" << weight << "\t\t" << tuition << "\t\t" << totalCost << endl;
}

void athlete::deleteAthlete(athlete athletes[])
{
    int del;
    for (int i = 0; i < cell; i++)
    {
        cout << i + 1 << ". " << athletes[i].name << "\t\t" << athletes[i].plan << "\t" << athletes[i].weight << endl;
    }

    cout << "Enter athlete number (1 - " << cell << " ) that you want to delete:";
    cin >> del;

    cout << "Athlete " << athletes[del - 1].name << " will be deleted.\n";
    system("pause");

    for (int i = del - 1; i < cell - 1; i++)
    {
        athletes[i] = athletes[i + 1];
    }
    cell--;

    for (int i = 0; i < cell; i++)
    {
        athletes[i].view();
    }
}

int partition(athlete athletes[], int start, int end)
{

    int pivot = athletes[start].weight;

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (athletes[i].weight <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(athletes[pivotIndex].weight, athletes[start].weight);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (athletes[i].weight <= pivot)
        {
            i++;
        }

        while (athletes[j].weight > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(athletes[i++].weight, athletes[j--].weight);
        }
    }

    return pivotIndex;
}

void athlete::quickSort(athlete athletes[], int start, int end)
{
    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(athletes, start, end);

    // Sorting the left part
    quickSort(athletes, start, p - 1);

    // Sorting the right part
    quickSort(athletes, p + 1, end);
}

void admin::viewPlans(Shane &Shaneclub)
{
    cout << "Plan\t\t\t\t\t\tPrices\n";
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << Shaneclub.plans[i] << "\t\t" << Shaneclub.prices[i] << endl;
    }
}

void admin::viewBeginnerPoses(Shane &Shaneclub)
{
    cout << "\t10 Yoga Beginner Poses\n";
    cout << "Yoga Pose Type\t\tYoga Pose Name\n";
    for (int i = 0; i < 11; i++)
    {
        cout << i + 1 << ". ";
        for (int j = 0; j < 2; j++)
        {
            cout << Shaneclub.BeginnerPoses[i][j] << "\t\t";
        }
        cout << endl;
    }
}

void admin::viewIntermediatePoses(Shane &Shaneclub)
{
    cout << "\t10 Yoga Intermediate Poses\n";
    cout << "Yoga Pose Type\t\tYoga Pose Name\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << Shaneclub.IntermediatePoses[i][j] << "\t\t";
        }
        cout << endl;
    }
}

void admin::viewTuitionPrices(Shane &Shaneclub)
{
    cout << "1. Online Private Tuition (" << Shaneclub.TuitionPrices[0] << "kyats per session)\n";
    cout << "2. Offline Private Tuition (" << Shaneclub.TuitionPrices[1] << "kyats per session)\n";
}

void admin::modifyPlanPrice(Shane &Shaneclub)
{
    int x;
    cout << "Plan\t\t\t\t\t\tPrices\n";
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << Shaneclub.plans[i] << "\t\t" << Shaneclub.prices[i] << endl;
    }
    cout << "Enter a number of the plan that you want to modify:";
    cin >> x;

    cout << "Old Plan = " << Shaneclub.plans[x - 1] << "\t\t" << Shaneclub.prices[x - 1] << endl;
    cout << "Enter new price:";
    cin >> Shaneclub.prices[x - 1];
    cout << "Modify Successful!\n";
    cout << "Plan\t\t\t\t\t\tPrices\n";
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << Shaneclub.plans[i] << "\t\t" << Shaneclub.prices[i] << endl;
    }
    system("pause");
}

void admin::modifyBeginnerPoses(Shane &Shaneclub)
{
    int x;
    cout << "\t10 Yoga Beginner Poses\n";
    cout << "Yoga Pose Type\t\tYoga Pose Name\n";
    for (int i = 0; i < 11; i++)
    {
        cout << i + 1 << ". ";
        for (int j = 0; j < 2; j++)
        {
            cout << Shaneclub.BeginnerPoses[i][j] << "\t\t";
        }
        cout << endl;
    }

    cout << "Enter the number of the pose that you want to modify:";
    cin >> x;

    cout << "Old Pose = " << Shaneclub.BeginnerPoses[x - 1][0] << "\t\t" << Shaneclub.BeginnerPoses[x - 1][1] << endl;
    cout << "Enter new Pose type:";
    cin.ignore();
    getline(cin, Shaneclub.BeginnerPoses[x - 1][0]);
    cout << "Enter new Pose name:";
    cin.ignore();
    getline(cin, Shaneclub.BeginnerPoses[x - 1][1]);
    cout << "Yoga Pose Type\t\tYoga Pose Name\n";
    for (int i = 0; i < 11; i++)
    {
        cout << i + 1 << ". ";
        for (int j = 0; j < 2; j++)
        {
            cout << Shaneclub.BeginnerPoses[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << "Modify Successful!!!\n";
}

void admin::addBeginnerPose(Shane &Shaneclub)
{
    int n = 0;
    while (Shaneclub.BeginnerPoses[n][0] != "")
    {
        n++;
    }

    if (n >= 30)
    {
        cout << "The array is full. Cannot add more poses.";
        return;
    }
    cout << "Enter new Pose type:";
    string newType;
    cin.ignore();
    getline(cin, newType);
    Shaneclub.BeginnerPoses[n][0] = newType;

    cout << "Enter new Pose name:";
    string newName;
    // cin.ignore();
    getline(cin, newName);
    Shaneclub.BeginnerPoses[n][1] = newName;

    for (int i = 0; i <= n; i++)
    {
        cout << i + 1 << ". ";
        for (int j = 0; j < 2; j++)
        {
            cout << Shaneclub.BeginnerPoses[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << "New Pose successfully added!!";
}

void admin::modifyIntermediatePoses(Shane &Shaneclub)
{
    int x;
    cout << "\t10 Yoga Intermediate Poses\n";
    cout << "Yoga Pose Type\t\tYoga Pose Name\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << Shaneclub.IntermediatePoses[i][j] << "\t\t";
        }
        cout << endl;
    }

    cout << "Enter the number of the pose that you want to modify:";
    cin >> x;

    cout << "Old Pose = " << Shaneclub.IntermediatePoses[x - 1][0] << "\t\t" << Shaneclub.IntermediatePoses[x - 1][1] << endl;
    cout << "Enter new Pose type:";
    cin >> Shaneclub.IntermediatePoses[x - 1][0];
    cout << "Enter new Pose name:";
    cin >> Shaneclub.IntermediatePoses[x - 1][1];
    cout << "Yoga Pose Type\t\tYoga Pose Name\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << Shaneclub.IntermediatePoses[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << "Modify Successful!!!";
}

void admin::addIntermediatePoses(Shane &Shaneclub)
{

    int n = 0;
    while (Shaneclub.BeginnerPoses[n][0] != "")
    {
        n++;
    }

    if (n >= 30)
    {
        cout << "The array is full. Cannot add more poses.";
        return;
    }

    cout << "Enter new Pose type:";
    string newType;
    cin.ignore();
    getline(cin, newType);
    Shaneclub.BeginnerPoses[n][0] = newType;

    cout << "Enter new Pose name:";
    string newName;
    // cin.ignore();
    getline(cin, newName);
    Shaneclub.BeginnerPoses[n][1] = newName;

    for (int i = 0; i <= n; i++)
    {
        cout << i + 1 << ". ";
        for (int j = 0; j < 2; j++)
        {
            cout << Shaneclub.BeginnerPoses[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << "New Pose successfully added!!";
}

void admin::modifyTuitionPrices(Shane &Shaneclub)
{
    int x;
    cout << "1. Online Private Tuition (" << Shaneclub.TuitionPrices[0] << "kyats per session)\n";
    cout << "2. Offline Private Tuition (" << Shaneclub.TuitionPrices[1] << "kyats per session)\n";

    cout << "Enter the number of the tuition price that you want to change:";
    cin >> x;

    cout << "Old Price = " << Shaneclub.TuitionPrices[x - 1] << endl;
    cout << "Enter new Price:";
    cin >> Shaneclub.TuitionPrices[x - 1];
    cout << "1. Online Private Tuition (" << Shaneclub.TuitionPrices[0] << "kyats per session)\n";
    cout << "2. Offline Private Tuition (" << Shaneclub.TuitionPrices[1] << "kyats per session)\n";
    cout << "Modify Successful!!!";
}