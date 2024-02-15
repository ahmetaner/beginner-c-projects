// Login and Registration System.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <string>

class User {
	public:
		std::string nickname;
		std::string password;
};

void inputs(User* user, int user_num);
void entry_menu(User* user, int user_num);
void comparation(std::string nicknmame, std::string password, std::string nickname, int  user_num);

int main()
{
	int user_num = 0;
	std::cout << "How many user there are?" << std::endl;
	std::cin >> user_num;
	User* user = new User[user_num];
	inputs(user, user_num);
	entry_menu(user, user_num);
	

	delete[] user;
}

void inputs(User* user, int user_num) {
	for (int i = 0; i < user_num; ++i) {
		std::string password = "";
		std::cout << "Enter nickname of " << i + 1 << "th person. > ";
		std:: cin >> (user + i)->nickname;
		std::cout << "Enter password of " << i + 1 << "th person. > ";
		std::cin >> (user + i)->password;
	}
}

void comparation(User* user, std::string password, std::string nickname, int user_num) {
	bool account_found = false;
	for (int i = 0; i < user_num; i++) {
		if (nickname == (user + i)->nickname) {
			if (password == (user + i)->password) {
				std::cout << "Log in is succefful.";
			}
			else {
				std::cout << "Log in is unsuccefful.";
			}
			account_found = true;
		}
	}
	if (account_found == false) {
		std::cout << "Account could not found.";
	}
	
}

void entry_menu(User* user, int user_num) {
	std::string possible_nname = "";
	std::string possible_password = "";
	std::cout << "Please enter a nickname > ";
	std::cin >> possible_nname;
	std::cout << "Please enter the password > ";
	std::cin >> possible_password;
	comparation(user, possible_password, possible_nname, user_num);

}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
