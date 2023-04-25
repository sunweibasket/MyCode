#include <memory>
#include <string>

class StrVec
{
private:
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    // 在拷贝或赋值被使用，返回两个指针，一个是新空间的开始位置，另外一个是拷贝的尾后位置
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();
    // 1.构造更大的string数组分配内存
    // 2.前半部分构造原有的数据
    // 3.删除原有的数组，并且释放这一段内存
    void reallocate();

    static std::allocator<std::string> alloc; // 分配元素
    std::string *elements;                    // 指向首个元素
    std::string *first_free;                  // 指向首个空闲元素
    std::string *cap;                         // 指向尾后位置

public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    // 拷贝构造函数
    StrVec(const StrVec &);
    // 移动构造函数
    StrVec(StrVec &&) noexcept;
    // 赋值操作符
    StrVec &operator=(const StrVec &);
    // 移动操作符
    StrVec &operator=(StrVec &&) noexcept;

    ~StrVec();

    void push_back(const std::string &);
    // 移动版本的push_back
    void push_back(std::string &&s);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
};

StrVec::StrVec(const StrVec &s)
{
    auto newData = alloc_n_copy(s.begin(), s.end());
    elements = newData.first;
    first_free = cap = newData.second;
}

StrVec::StrVec(StrVec &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    // 新的Strvec接管的旧的内存管理
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(const StrVec &s)
{
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&s) noexcept
{
    // 检查是否时自身，如果是自身在free就会出现异常
    if (this != &s)
    {
        free();
        elements = s.elements;
        first_free = s.first_free;
        cap = s.cap;
        s.elements = s.first_free = s.cap = nullptr;
    }
    return *this;
}
StrVec::~StrVec()
{
    free();
}
void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s); // 完成后指针++
}

void StrVec::push_back(std::string &&s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto newcap = size() ? size() * 2 : 1;
    auto newData = alloc.allocate(newcap);
    auto newElements = newData;
    auto dest = newData;
    for (size_t i = 0; i != size(); i++)
        alloc.construct(dest++, std::move(*elements++));
    // make_move_iteratorn()转换成右值迭代器，uninitialized_copy()构造时则使用移动构造
    // dest = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), newData)
    free();
    elements = newData;
    first_free = dest;
    cap = elements + newcap;
}
