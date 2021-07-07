# ft_containers

The multiple available containers in C++ all have a very different usage. 
To make sure you understand them all, let’s re-implement some of them according to the C++98 standard!


**Subject:**
In this project, you will implement the various container types of the C++ standard template library
- member functions, Non-member and overloads are expected.
- respect the naming
- You must justify your inner data structure for each container (using a simple array for a map is not ok).
- If the container has an iterator system, you must implement it. 
- Iterators_traits, reverse_iterator, enable_if, is_integral, equal/lexicographical compare, std::pair, std::make_pair, must be reimplemented.
- You cannot implement more public functions than the ones offered in the standard containers. Everything else must be private or protected. Each public function/- variable must be justified.
- For non-member overloads, the keyword friend is allowed. Each use of friend must be justified and will be checked during evaluation.
- You must turn in the following containers and their associated functions:
  - Vector
  - Stack
  - Map
- Your stack will use your vector class as default underlaying container, it must still be compatible with others containers like the STL one.
- You are allowed to use the STD library

**Usage:**
I have included a main which compares my containers with STL containers
To test run the following commands in the terminal

```
git clone //https://github.com/avan-dam/ft_containers.git
cd ft_containers
make
```

To test run
```
./ft_containers
```
This can be seen in the screenshot below

<img width="550" alt="Screenshot 2021-07-05 at 19 28 15" src="https://user-images.githubusercontent.com/61982496/124504153-2d1c6c80-ddc7-11eb-968f-a5486570267b.png">

Currently working on this project (incomplete)! 
