#include "Zombie.hpp"
#include <sstream>

Zombie *zombieHorde(int N, std::string name)
{
    std::stringstream ss;
    Zombie *horde;

    horde = new Zombie[N];
    // horde = new Zombie[N](); <- 이 코드 또한 인자 없이 생성하는 생성자를 정상적으로 호출하나,
    // 기본적으로 클래스의 인스턴스 배열을 한번에 new로 할당할 때는 인자를 넘겨 초기화하는 형태가 불가능하므로
    // (즉 new Zombie[N]("test");와 같은 형태가 불가)
    // 배열을 한번에 할당할 때는 위와 같은 형태로 작성하는게 스탠다드하다.

    for (int i = 0; i < N; i++)
    {
        ss << i;
        horde[i].setName(name + ss.str());
        ss.str("");
    }
    return (horde);
}
