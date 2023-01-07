#include <iostream>
#include <set>

template <typename T, typename C>
void print_set(std::set<T, C> &s)
{
    for (const auto &elem : s)
    {
        std::cout << elem << " " << std::endl;
    }
}

class Todo
{
    int priority;
    std::string job_desc;

public:
    Todo(int priority, std::string job_desc)
        : priority(priority), job_desc(job_desc) {}

    friend struct TodoCmp;

    friend std::ostream &operator<<(std::ostream &o, const Todo &td);
};

struct TodoCmp
{
    bool operator()(const Todo &t1, const Todo &t2) const
    {
        if (t1.priority == t2.priority)
            return t1.job_desc < t2.job_desc;
        return t1.priority > t2.priority;
    }
};

std::ostream &operator<<(std::ostream &o, const Todo &td)
{
    o << "[ 중요도: " << td.priority << "] " << td.job_desc;
    return o;
}

int main()
{
    std::set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);

    std::cout << "순서대로 정렬되서 나온다" << std::endl;
    print_set(s);

    std::cout << "20이 s의 원소인가요? :: ";
    auto itr = s.find(20);
    if (itr != s.end())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    std::cout << "25가 a의 원소인가요? :: ";
    itr = s.find(25);
    if (itr != s.end())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    // std::set<Todo> todos;

    // todos.insert(Todo(1, "농구 하기"));
    // todos.insert(Todo(2, "수학 숙제 하기"));
    // todos.insert(Todo(1, "프로그래밍 프로젝트"));
    // todos.insert(Todo(3, "친구 만나기"));
    // todos.insert(Todo(2, "영화 보기"));

    // print_set(todos);

    // std::cout << "-----------" << std::endl;
    // std::cout << "숙제를 끝냈다면!" << std::endl;

    // todos.erase(todos.find(Todo(2, "수학 숙제 하기")));
    // print_set(todos);

    std::set<Todo, TodoCmp> todos;

    todos.insert(Todo(1, "농구 하기"));
    todos.insert(Todo(2, "수학 숙제 하기"));
    todos.insert(Todo(1, "프로그래밍 프로젝트"));
    todos.insert(Todo(3, "친구 만나기"));
    todos.insert(Todo(2, "영화 보기"));

    print_set(todos);

    std::cout << "-----------" << std::endl;
    std::cout << "숙제를 끝냈다면!" << std::endl;

    todos.erase(todos.find(Todo(2, "수학 숙제 하기")));
    print_set(todos);
}