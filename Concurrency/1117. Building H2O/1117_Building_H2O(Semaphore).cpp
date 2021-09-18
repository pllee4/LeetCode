#include <semaphore.h>

class H2O {
 public:
  H2O() {
    // init semaphore for 2 hydrogen threads to be able to access
    sem_init(&hydrogen_sem_, 2, 2);
    // init semaphore for 1 oxygen threads to be able to access
    sem_init(&oxygen_sem_, 1, 1);

    hydrogen_count_ = 0;
  }

  void hydrogen(function<void()> releaseHydrogen) {
    sem_wait(&hydrogen_sem_);
    releaseHydrogen();

    std::unique_lock<std::mutex> lock(mutex_);

    if (++hydrogen_count_ == 2) {
      hydrogen_count_ = 0;
      sem_post(&oxygen_sem_);
    }
  }

  void oxygen(function<void()> releaseOxygen) {
    sem_wait(&oxygen_sem_);
    releaseOxygen();
    sem_post(&hydrogen_sem_);
    sem_post(&hydrogen_sem_);
  }

 private:
  sem_t hydrogen_sem_;
  sem_t oxygen_sem_;
  std::mutex mutex_;

  int hydrogen_count_;
};