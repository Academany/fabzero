# By Tomorrow?! Time and project management
<!-- TOC -->

1. [Laws of time](#laws-of-time)
2. [The two mistakes](#the-two-mistakes)
3. [Listing all the required tasks](#listing-all-the-required-tasks)
4. [Assigning time to each task](#assigning-time-to-each-task)
5. [Parallel vs Serial development](#parallel-vs-serial-development)
6. [Rescheduling](#rescheduling)
7. [Spiral development. Failing as fast as you can](#spiral-development-failing-as-fast-as-you-can)
8. [Debugging. When things go wrong](#debugging-when-things-go-wrong)
9. [Deliver](#deliver)

<!-- /TOC -->
## Laws of time

Time has three peculiarities, which I elevated to laws.

* **First** law of time. **Everything consumes time**
* **Second** law of time. **You can't stop time**. There is nothing you can do about it. You can pause but time will not
* **Third** law of time. **Time x Effort = constant**. Given an initial large time to do something, the effort will be low. As time tends to zero, the effort tends to infinite.

## The two mistakes

There are **two mistakes** people make when **managing time**. The **first one** is thinking about it as a continuous, **infinite** line, whose duration is **relative**. Do this and you will always be late. You need to start thinking about time as a physical dimension like length, finite and perfectly measurable.

The **second mistake is overestimating time**. We tend to think, given a deadline, that we have plenty of time to finish a task. This is a big mistake. Let's break down a one week deadline, for example.

**Consider that a week has 5 days**, not 7. Some people affirm they will work 7 days. They fail miserably.

In theory, you will have 8 hours available everyday for working/studying, often splitted between the morning and the afternoon. But that time will be reduced because of the 3 reasons below.

* Assume that **an hour is 50 minutes**
* Assume **you will spend 1 hour every morning/afternoon in emails**, calls, messages, **and the like**. If not more
* Assume that **you will take a 30 minutes break** at mid morning/afternoon

So in reality you have roughly 5h. That is assuming that you are not a social network addict. To recap, **in a week you have less than 24h of continuous work**.

## Listing all the required tasks

The idea behind project management is simple: To allocate every task in our project in a bidimensional matrix of time (days as columns, hours as rows). We only have two uncertains: **The first uncertain is knowing how many pieces (tasks) we have in the puzzle**. The second uncertain is how long it will take to complete each task. Sometimes you will forget the first law of time and you will not consider a task, because you think it won't consume a noticeable amount of time. Here are a list of commonly ignored tasks that make your project fail:

* Determining the project management strategy
* Researching
* Lab cleanup
* Documenting
* Multimedia processing
* Testing
* Allocated time for unforeseen
* Troubleshooting and debugging (no, this is not an unforeseen, this is a mathematical certain)
* Rehearshing a presentation

## Assigning time to each task

In project management there are two variants of how to assign time to a task. One is called **demand-side**, in which you start a task and wait until it is completed to continue. You assign time this way for tasks that are out of your control, like the time it takes to a machine for milling a board or to a computer for processing something.

But for things that are under your control -like designing a circuit, or researching for inflatable structures- you don't keep going until you finish. Because you will never finish. Instead, you will use the **supply-side** time management, in which you decide beforehand how much time are you going to spend on a task. You do the best you can in that time, and then you stop and switch to the next task. You have to estimate the time (according to your skills) and stick to it. Over time you will become more realistic in your supply-time estimations.

Work backwards from the deadline and forward from current time, iterating until you find a match.

## Parallel vs Serial development

It is important to analize which tasks are independent, so that you can execute them in parallel and which tasks are dependent and you have to wait to start them. Always **throw as many parallel processes as your sanity can handle**. In particular, the **documenting** process should be **always running in parallel**.

## Rescheduling

If you **overestimated time** or **ignored the third law** of time you will probably need to reschedule. It will also be the time to **drop some unrealistic goals** you had in mind. Remember that the most important thing is to deliver.

## Spiral development. Failing as fast as you can

If you try to create the project you have in your mind in one go, you will fail. Nature never achieves perfection in one attempt, but in a series of infinite iterations. At least, you have to reach the following milestone iterations:

1. Make it work. There is a fundamental design principle called *satisfizing* and here it is summarized: Doesn't matter how, but it has to work.
2. Make it integrated and resilient. At the very minimum, make it holdable in one hand and resistant to shakes
3. Make it nice

Refine your project over and over until

1. You are happy with the result
2. You run out of time

## Debugging. When things go wrong

Things will go wrong, the only thing you don't know is how much. The following example is about a circuit board. But it could apply for anything else: Imagine you made a circuit board and it doesn't work. Somehow, you find there is problem in the design.

> **Think about it:** What do you do?

In fact you have to do 2 things.

1. **Top-down debbuging**: Fix the board. Do not make a new board. The goal is learning, not succeeding. Even if you found the problem in the design, no one said that this was the only flaw. Worse is the case if you make a new board and succeed, like the donkey and the flute kid's story.
2. **Bottom-up debugging**: Find the root cause that originated the flaw. Sometimes the root cause is hidden behind intermediate causes. Ask yourself *why did that happen* a few times until you find the root cause.

> **Free tip:** When debugging, always smile. Tomorrow it will be worse.

## Deliver

The only thing certain in project management is that **there is a deadline**. At that day you **have** to deliver. Doesn't matter if it is not what you wanted, if you don't like it, or if you are halfway done. That day, you deliver whatever you have. Afterwards, if you want, you can meditate about what changes you should make in the future to achieve your goals. But remember, you deliver that ugly thing you made. Always. **Deliver**.

---
[Back to Summary](../summary.md)
