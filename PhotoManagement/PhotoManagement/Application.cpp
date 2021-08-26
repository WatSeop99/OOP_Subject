#include <iomanip>
#include "Application.h"

List<PhotoType> Base::master; // static ���� �ʱ�ȭ

// ���� ���� ���� �޴�
void Application::Run() {
	using namespace std;

	int command;
	while (command = GetCommand()) {
		cout.setf(ios::left, ios::adjustfield);
		switch (command) {
		case 0:
			return;
		case 1:
			AddPhoto(); // ���� �߰�
			break;
		case 2:
			DeletePhoto(); // ���� ����
			break;
		case 3:
			FindPhoto(); // ���� �˻�
			break;
		case 4:
			FindPhotoByEvent(); // �̺�Ʈ�� ���� �˻�
			break;
		case 5:
			DisplayList(); // ���� ��� ���
			break;
		case 6:
			ReadAllFromFile(); // �ܺ����Ϸκ��� ������ �б�
			break;
		case 7:
			WriteAllToFile(); // �ܺ����Ͽ� ������ ����
			break;
		case 8:
			DisplayListUsingEL(); // �̺�Ʈ ����Ʈ�� �̿��Ͽ� ������� ���
			break;
		case 9:
			SearchByPhotoNameNEvent(); // ���� �̸��� �̺�Ʈ�� �˻�
			break;
		case 10:
			SearchByEventNContents(); // ���� �̺�Ʈ�� �������� �˻�
			break;
		default:
			cout << "Invalid operation \n";
		}
	}
}

// ���� �߰�
void Application::AddPhoto() {
	PhotoType input;
	if (!input.ReadItemFromKB()) // ���� ���� �Է�
		return;
	AddPhotoToList(input);
}

// ���� ����
void Application::DeletePhoto() {
	std::string name;
	std::cout << "\t ������ ������ �Է� -->";
	std::cin >> name;

	PhotoType record(name);
	master.DeleteItem(record);
}

// ���� �˻�
void Application::FindPhoto() {
	std::string name;
	std::cout << "\t ã���� �ϴ� ������ �Է� --> ";
	std::cin >> name;
	
	PhotoType record(name), *pPtr;
	pPtr = master.RetrievePtr(record);
	if (!pPtr)
		std::cout << "\n%%%% ��ġ�ϴ� ������ ã�� ���߽��ϴ� %%%%\n";
	else
		pPtr->DisplayOnScreen();
}

// �̺�Ʈ�� ���� �˻�
void Application::FindPhotoByEvent() {
	using namespace std;

	string eName;
	cout << "\t ã���� �ϴ� �̺�Ʈ �� �Է� --> ";
	cin >> eName;

	PhotoType record;
	bool found = false;
	cout << "\t" << "  " << setw(14) << "[������]" << setw(14) << "[�̺�Ʈ ��]" << setw(14) << "[���� ����]" << endl;
	master.ResetList();
	while (master.GetNextItem(record)) {
		if (record.IsEventEqual(eName)) {
			cout << '\t';
			record.DisplayOnScreen();
			found = true;
		}
	}
	if (!found)
		cout << "\n%%%% ��ġ�ϴ� ������ ã�� ���߽��ϴ� %%%%\n";
}

// ��ϵǾ��ִ� ���� ����� ȭ�鿡 ���
void Application::DisplayList() {
	using namespace std;

	cout << "\t ***  ���� ����Ʈ ȭ�� ���  ***\n";
	cout << "\t" << "  " << setw(14) << "[���� ��]" << setw(14) << "[�̺�Ʈ��]" << setw(14) << "[���� ����]" << endl;

	PhotoType record;
	master.ResetList();
	while (master.GetNextItem(record)) {
		cout << '\t';
		record.DisplayOnScreen();
	}
}

// ���� �޴� ����
int Application::GetCommand() {
	using namespace std;

	int temp;
	while (1)
	{
		cout << "\n\t--- ID ------------ ������ �۾� --------------------" << endl;
		cout.setf(ios::left, ios::adjustfield);
		cout << "\t|" << setw(50) << "    0. ���α׷� ����" << "|\n";
		cout << "\t|" << setw(50) << "    1. �� ���� �߰�" << "|\n";
		cout << "\t|" << setw(50) << "    2. ���� ����" << "|\n";
		cout << "\t|" << setw(50) << "    3. ���� �̸����� �˻�" << "|\n";
		cout << "\t|" << setw(50) << "    4. �̺�Ʈ �̸����� �˻�" << "|\n";
		cout << "\t|" << setw(50) << "    5. ����Ʈ�� ��� ������ ȭ�鿡 ���" << "|\n";
		cout << "\t|" << setw(50) << "    6. ���Ͽ��� ��� ���� �б�" << "|\n";
		cout << "\t|" << setw(50) << "    7. ����Ʈ�� ��� ������ ���Ͽ� ���" << "|\n";
		cout << "\t|" << setw(50) << "    8. event list�� �̿��� �̺�Ʈ �˻�" << "|\n";
		cout << "\t|" << setw(50) << "    9. �̺���� ���������� �˻�" << "|\n";
		cout << "\t|" << setw(50) << "    10.�̺���� ���� Ű����� �˻�" << "|\n";
		cout << "\t----------------------------------------------------" << endl;
		cout << "\t ������ �۾� ���� --> ";
		if (cin.fail() || !(cin >> temp) || temp < 0 || temp>10) {	// input fail or input value is out of bound
			cout << "\t    ### ��ȿ���� ���� ���. �ٽ� �Է��ϼ���  ####" << endl;
			cin.clear();	//clear flag
			cin.ignore(INT_MAX, '\n');	//empty input buffer
		}
		else {
			cin.clear();  // clear flag
			cin.ignore(INT_MAX, '\n');  // empty input buffer
			return temp;
		}
	}
}

// �ܺ����Ϸκ��� �����͸� �о��
bool Application::ReadAllFromFile() {
	using namespace std;

	string photoName, eventName;
	master.MakeEmpty();
	ifstream inFile;
	inFile.open(inFileName);
	// �ܺ����� �б� ���н�
	if (!inFile.is_open()) {
		cout << "Unable to Open input file" << endl;
		return false;
	}

	PhotoType record;
	while (record.ReadRecordFromFile(inFile))
		AddPhotoToList(record);
	return true;
}

// �ܺ����Ͽ� �����͸� ��
bool Application::WriteAllToFile() {
	using namespace std;

	ofstream outFile;
	outFile.open(outFileName);
	// �ܺ����� �б� ���н�
	if (!outFile.is_open()) {
		cout << "Unable to Open output file" << endl;
		return false;
	}

	PhotoType record;
	master.ResetList();
	while (master.GetNextItem(record))
		record.WriteRecordToFile(outFile);
	return true;
}

// ���������� master list�� �߰�
bool Application::AddPhotoToList(PhotoType& item) {
	// master list�� ���� �ߺ� �߰� ����
	if (!master.GetLength()) // ������ ���ٸ�
		master.PutItem(item);
	else {
		int found = master.Retrieve(item); // �ߺ� üũ
		if (found == -1)
			master.PutItem(item);
		else
			return false;
	}

	// event list�� ���� �ߺ� �߰� ����
	if (!eventList.GetLength()) { // ������ ���ٸ�
		EventType record(item.GetEventName());
		record.AddPhotoKey(item.GetPhotoName());
		eventList.PutItem(record);
	}
	else {
		EventType record(item.GetEventName()), *ptr;
		ptr = eventList.RetrievePtr(record); // �ߺ� üũ
		if (!ptr) {
			record.AddPhotoKey(item.GetPhotoName());
			eventList.PutItem(record);
		}
		else
			ptr->AddPhotoKey(item.GetEventName());
	}
	return true;
}

// �̺�Ʈ ����Ʈ�� �̿��Ͽ� ���� ���
void Application::DisplayListUsingEL() {
	std::string name;
	std::cout << "\t ã���� �ϴ� �̺�Ʈ �� �Է� --> ";
	std::cin >> name;

	EventType record(name), *ptr;
	ptr = eventList.RetrievePtr(record);
	if (ptr)
		ptr->DisplayDetails();
	else
		std::cout << "\n%%%% ��ġ�ϴ� ������ ã�� ���߽��ϴ� %%%%\n";
}

// ���� �̸��� �̺�Ʈ�� ���� �˻�
void Application::SearchByPhotoNameNEvent() {
	std::string pName, eName;
	std::cout << "\t << �̺�Ʈ�� ������� ���� �˻�  >>\n \t�˻��� ������ �̺�Ʈ�� �������� �Է��ϼ��� --> ";
	std::cin >> eName >> pName;

	EventType record(eName), *ePtr;
	PhotoType* pPtr;
	ePtr = eventList.RetrievePtr(record);
	if (ePtr) {
		pPtr = ePtr->FindByNameKey(pName);
		if (pPtr)
			pPtr->DisplayOnScreen();
		else
			std::cout << "\n%%%% ��ġ�ϴ� ������ ã�� ���߽��ϴ� %%%%\n";
	}
	else
		std::cout << "\n%%%% ��ġ�ϴ� ������ ã�� ���߽��ϴ� %%%%\n";
}

// ���� �̺�Ʈ�� �������� ���� �˻�
void Application::SearchByEventNContents() {
	std::string eName, contents;
	std::cout << "\t << �̺�Ʈ�� ������� �ܾ�� ���� �˻�  >>\n \t�˻��� ������ �̺�Ʈ�� ���� �ܾ �Է��ϼ��� --> ";
	std::cin >> eName >> contents;

	EventType record(eName), *ePtr;
	PhotoType* pPtr;
	ePtr = eventList.RetrievePtr(record);
	if (ePtr) {
		pPtr = ePtr->FindByContentsKey(contents);
		if (pPtr)
			pPtr->DisplayOnScreen();
		else
			std::cout << "\n%%%% ��ġ�ϴ� ������ ã�� ���߽��ϴ� %%%%\n";
	}
	else
		std::cout << "\n%%%% ��ġ�ϴ� ������ ã�� ���߽��ϴ� %%%%\n";
}