#include <stdlib.h> // malloc, free
#include <stdio.h> // printf
#include <unistd.h> // write, usleep
#include <stdbool.h>
#include <pthread.h> // mutex: init destroy lock unlock. Threads: create join detach
#include <sys/time.h> // gettimeofday
#include <limits.h> // INT_MAX
#include <errno.h>

#define MAX_PHILOSOPHERS 200


/*
OPCODE for mutex and threads functions */
// enumeracja
typedef enum    e_opcode
{
    LOCK,
    UNLOCK,
    INIT,
    DESTROY,
    CREATE,
    JOIN,
    DETACH
}           t_opcode;
/*STRUCTURES*/
typedef pthread_mutex_t t_mtx;

typedef struct s_table t_table;

/*FORK*/
typedef struct  s_fork {
    t_mtx fork;
    int fork_id;
}               t_fork;

/*PHILO*/
typedef struct s_philosopher {
    int id;
    int meals_eaten;
    long last_meal_time;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    struct s_data *data;
} t_philosopher;


/*TABLE*/
typedef struct s_data {
    int num_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_meals;
    long start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t print_lock;
    t_philosopher *philosophers;
} t_data;

bool    validate_input(char *argv[]);
bool    validate_optional_input(const char *arg);
bool    is_valid_num(const char *arg);

int		init_data(t_data **project, int argc, char *argv[]);
void    error_exit(const char *error);
int	ft_atoi(const char *str);
int	ft_isnum(char c);
