#include <semaphore.h>

class DiningPhilosophers {
 public:
  DiningPhilosophers() {
    for (int i = 0; i < num_philosophers_; i++) sem_init(&forks_[i], 0, 1);
  }

  void wantsToEat(int philosopher, function<void()> pickLeftFork,
                  function<void()> pickRightFork, function<void()> eat,
                  function<void()> putLeftFork, function<void()> putRightFork) {
    int left = philosopher, right = (philosopher + 1) % num_philosophers_;
    // avoid deadlock when everyone is able to hold fork and waiting
    std::unique_lock<std::mutex> lock(mutex_);
    sem_wait(&forks_[left]);
    sem_wait(&forks_[right]);
    pickLeftFork();
    pickRightFork();
    eat();
    putRightFork();
    putLeftFork();
    sem_post(&forks_[left]);
    sem_post(&forks_[right]);
  }

 private:
  static constexpr int num_philosophers_ = 5;
  sem_t forks_[num_philosophers_];
  std::mutex mutex_;
};