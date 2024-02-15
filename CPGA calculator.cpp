// CPGA calculator.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
class Courses {
    public:
        int grade = 0;
        int course_AKTS = 0;
        std::string name = "";

};

float overal(int course_num, Courses* course_grades);
void inputs(Courses* course_grades, int course_number);


int main()
{    
    
    int course_number = 0;
    std::cout << "Enter the number of courses taken. > ";
    std::cin >> course_number;
    Courses* courses = new Courses[course_number];
    inputs(courses, course_number);
    std::cout << overal(course_number, courses);

    delete[] courses;
}


float overal(int course_num, Courses* course_grades) {
    int total = 0;
    int total_AKTS = 0;
    for (int i = 0; i < course_num; i++) {
        total += ((course_grades + i)->grade) * (course_grades + i)->course_AKTS;
        total_AKTS += (course_grades + i)->course_AKTS;
    }
    return (float)total / total_AKTS;
}

void inputs(Courses* courses, int course_number) {
    for (int i = 0; i < course_number; i++) {
        std::cout << "Enter the name of " << i + 1 << "th course. < ";
        std::cin >> courses[i].name;

        std::cout << "Enter the grade of " << i + 1 << "th course. < ";
        std::cin >> courses[i].grade;
        try
        {
            if (0 > courses[i].grade || 100 < courses[i].grade) {
                throw - 1;
            }
        }
        catch (int error)
        {
            std::cout << "Please enter proper input. Error code: " << error;
            break;
        }

        std::cout << "Enter the AKTS of " << i + 1 << "th course. < ";
        std::cin >> courses[i].course_AKTS;
        try
        {
            if (0 > courses[i].course_AKTS) {
                throw - 2;
            }
        }
        catch (int error)
        {
            std::cout << "Please enter proper input. Error code: " << error;
            break;
        }
    }
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
