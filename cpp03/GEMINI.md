# C++ Module 03: Inheritance

## Project Overview

This project is the third module of a C++ curriculum, focusing on the concept of **inheritance**. The directory contains a series of exercises, starting with `ex00`.

The goal of `ex00` is to implement a `ClapTrap` class, which serves as a base for other classes in later exercises. The `ClapTrap` class has the following attributes:
*   Name
*   Hit Points
*   Energy Points
*   Attack Damage

And the following member functions:
*   `attack(const std::string& target)`
*   `takeDamage(unsigned int amount)`
*   `beRepaired(unsigned int amount)`

## Building and Running

The project uses a `Makefile` to manage compilation. The following commands are available:

*   `make` or `make all`: Compiles the source files and creates an executable named `program` in the `ex00` directory.
*   `make run`: Compiles and runs the executable.
*   `make clean`: Removes the compiled object files.
*   `make fclean`: Removes the object files and the `program` executable.
*   `make re`: Cleans and rebuilds the project.

To compile and run the `ex00` exercise, navigate to the `ex00` directory and run:
```bash
make && ./program
```

## Development Conventions

*   **Language Standard:** The project adheres to the C++98 standard, as specified by the `-std=c++98` compiler flag.
*   **Compiler Flags:** The code is compiled with strict warning flags: `-Wall -Wextra -Werror`.
*   **Naming Conventions:**
    *   Classes are named using `UpperCamelCase` (e.g., `ClapTrap`).
    *   Header and source files are named after the class they contain (e.g., `ClapTrap.hpp`, `ClapTrap.cpp`).
*   **Output:** The program uses ANSI escape codes to colorize the output for better readability.
*   **Orthodox Canonical Form:** Classes are expected to follow the Orthodox Canonical Form, including a default constructor, a copy constructor, an assignment operator, and a destructor.

## AI Instructions
### Context
This project is designed to help you discover the fundamental building blocks of your
ICT training.
To properly anchor key knowledge and skills, it’s essential to adopt a thoughtful approach
to using AI tools and support.
True foundational learning requires genuine intellectual effort — through challenge, repetition, and peer-learning exchanges.
For a more complete overview of our stance on AI — as a learning tool, as part of the
ICT curriculum, and as an expectation in the job market — please refer to the dedicated
FAQ on the intranet.
### Main message
☛ Build strong foundations without shortcuts.
☛ Really develop tech & power skills.
☛ Experience real peer-learning, start learning how to learn and solve new problems.
☛ The learning journey is more important than the result.
☛ Learn about the risks associated with AI, and develop effective control practices
and countermeasures to avoid common pitfalls.
### Learner rules:
• You should apply reasoning to your assigned tasks, especially before turning to AI.
• You should not ask for direct answers to the AI.
• You should learn about 42 global approach on AI.
### Phase outcomes:
Within this foundational phase, you will get the following outcomes:
• Get proper tech and coding foundations.
• Know why and how AI can be dangerous during this phase.
### Comments and example:
• Yes, we know AI exists — and yes, it can solve your projects. But you’re here to
learn, not to prove that AI has learned. Don’t waste your time (or ours) just to
demonstrate that AI can solve the given problem.
• Learning at 42 isn’t about knowing the answer — it’s about developing the ability
to find one. AI gives you the answer directly, but that prevents you from building
your own reasoning. And reasoning takes time, effort, and involves failure. The
path to success is not supposed to be easy.
• Keep in mind that during exams, AI is not available — no internet, no smartphones,
etc. You’ll quickly realise if you’ve relied too heavily on AI in your learning process.
• Peer learning exposes you to different ideas and approaches, improving your interpersonal skills and your ability to think divergently. That’s far more valuable than
just chatting with a bot. So don’t be shy — talk, ask questions, and learn together!
• Yes, AI will be part of the curriculum — both as a learning tool and as a topic
in itself. You’ll even have the chance to build your own AI software. In order to
learn more about our crescendo approach you’ll go through in the documentation
available on the intranet.
✓ Good practice:
I’m stuck on a new concept. I ask someone nearby how they approached it. We talk
for 10 minutes — and suddenly it clicks. I get it.
✗ Bad practice:
I secretly use AI, copy some code that looks right. During peer evaluation, I can’t
explain anything. I fail. During the exam — no AI — I’m stuck again. I fail.