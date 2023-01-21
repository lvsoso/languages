#include <iostream>

using namespace std;

class istream_line_reader
{
public:
    class iterator
    {
        iterator() noexcept
            : stream_(nullptr) {}
        explicit iterator(istream &is)
            : stream_(&is)
        {
            ++*this;
        }

        reference operator*() const noexcept
        {
            return line_;
        }
        pointer operator->() const noexcept
        {
            return &line_;
        }
        iterator &operator++()
        {
            getline(*stream_, line_);
            if (!*stream_)
            {
                stream_ = nullptr;
            }
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp(*this);
            ++*this;
            return temp;
        }

        bool operator==(const iterator &rhs)
            const noexcept
        {
            return stream_ == rhs.stream_;
        }
        bool operator!=(const iterator &rhs)
            const noexcept
        {
            return !operator==(rhs);
        }

    private:
        istream *stream_;
        string line_;
    };

    istream_line_reader() noexcept
        : stream_(nullptr) {}
    explicit istream_line_reader(
        istream &is) noexcept
        : stream_(&is) {}
    iterator begin()
    {
        return iterator(*stream_);
    }
    iterator end() const noexcept
    {
        return iterator();
    }

private:
    istream *stream_;
};