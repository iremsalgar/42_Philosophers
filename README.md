# 42_Philosophers

## Philosophers problemi nedir?

"Filozoflar" problemi, bir grup filozofun masada yemek yerken, her filozofun bir kaşık ile yemek yeme işlemini modelleyen bir problemdir. Bu problemde, her filozofun bir kaşık olduğu varsayılır ve her filozofun sol ve sağ tarafında da bir kaşık vardır. Her filozof, yemek yemek için iki kaşıkın olmasını bekler. Eğer her iki kaşık da mevcutsa, filozof yemek yer, ancak eğer bir kaşık yoksa filozof bekler. Bu problem, mutex kullanılarak çözülebilir.

Bu problemi çözmek için, her filozofun bir thread oluşturulur ve bu threadler üzerinden filozofların yemek yemesi ve düşünme işlemleri gerçekleştirilir. Ayrıca, her filozofun kullanacağı kaşıklar için mutex değişkenleri oluşturulur ve bu mutex değişkenleri ile kaşıkların kilidi alınıp açılması işlemleri gerçekleştirilir. Böylece, her filozofun yemek yemesi sırasında birbirlerine göre beklemesi sağlanır ve veri hatası önlenir.


## THREAD nedir?

Thread, bir programda birden fazla iş parçacığının aynı anda çalıştırılabildiği anlamına gelir. Threadler, bir programın birkaç işlemi aynı anda yapabilmesine olanak verir, böylece program daha hızlı çalışır. Örneğin, bir programda bir thread bir dosyayı okurken, diğer thread bir veritabanına bağlanabilir. Bu sayede, bir işlem tamamlanırken diğer işlemler de aynı anda çalıştırılabilir.

Threadler, genellikle bir işletim sisteminde bir programın çalışması sırasında oluşturulur. Bir programda birden fazla thread oluşturulabilir ve her bir thread farklı bir işlemi yapabilir. Bu sayede, bir program daha hızlı çalışabilir ve daha verimli bir şekilde kullanılabilir.

Burada, C dilinde bir thread oluşturma örneği verilebilir:
```c
#include <pthread.h>
#include <stdio.h>

// İki farklı thread için işlev tanımlanır
void *function1(void *arg)
{
  printf("Function 1 çalışıyor\n");
  return NULL;
}

void *function2(void *arg) 
{
  printf("Function 2 çalışıyor\n");
  return NULL;
}

int main(int argc, char *argv[]) 
{
  pthread_t thread1, thread2; // İki thread için değişkenler oluşturulur

  // İki thread oluşturulur
  pthread_create(&thread1, NULL, function1, NULL);
  pthread_create(&thread2, NULL, function2, NULL);

  // Threadler bekletilir
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("İki thread tamamlandı\n");
  return 0;
}
```
Bu kod, pthread_create() fonksiyonu kullanılarak iki farklı thread oluşturur ve her bir threadin içinde farklı bir işlev yer alır. Bu threadler, pthread_join() fonksiyonu ile bekletilir ve sonra "Function 1 çalışıyor" ve "Function 2 çalışıyor" mesajları ekrana yazdırılır. Son olarak, "İki thread tamamlandı" mesajı ekrana yazdırılır.

Bu örnekte, iki farklı işlevin aynı anda çalıştırılabildiği gösterilmiştir. Bu örnekte, işlevler yalnızca ekrana bir mesaj yazdırır, ancak threadler genellikle daha karmaşık işlemleri yapabilirler.

```c
#include <pthread.h>
#include <stdio.h>

// İki farklı thread için işlev tanımlanır
void *function1(void *arg) 
{
  printf("Function 1 çalışıyor\n");
  return NULL;
}

void *function2(void *arg) 
{
  printf("Function 2 çalışıyor\n");
  return NULL;
}

int main(int argc, char *argv[]) 
{
  pthread_t thread1, thread2; // İki thread için değişkenler oluşturulur

  // İki thread oluşturulur
  if (pthread_create(&thread1, NULL, function1, NULL) != 0) 
  {
    printf("Thread oluşturulamadı\n");
    return 1;
  }
  if (pthread_create(&thread2, NULL, function2, NULL) != 0) 
  {
    printf("Thread oluşturulamadı\n");
    return 1;
  }

  // Threadler bekletilir
  if (pthread_join(thread1, NULL) != 0) 
  {
    printf("Thread bekletilemedi\n");
    return 1;
  }
  if (pthread_join(thread2, NULL) != 0) 
  {
    printf("Thread bekletilemedi\n");
    return 1;
  }

  printf("İki thread tamamlandı\n");
  return 0;
}
```
Özellikle, pthread_create() ve pthread_join() fonksiyonları için hata kontrolü yapılmıştır ve eğer bir hata oluşursa, kullanıcıya uygun bir hata mesajı gösterilmiştir.

### pthread_create

pthread_create() fonksiyonu, C dilinde bir thread oluşturmak için kullanılır. Bu fonksiyon, bir thread oluşturulmasını ve bu threadin bir işlevi çalıştırmasını sağlar.

Bu fonksiyon, aşağıdaki şekilde kullanılır:

```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg);
```
Bu fonksiyonun ilk parametresi, oluşturulacak thread için bir pthread_t tipinde değişken gerektirir. Bu değişken, oluşturulan threadin tanımlayıcısını tutar. İkinci parametre, threadin özelliklerini tanımlayan bir pthread_attr_t tipinde değişkendir ve genellikle NULL olarak ayarlanır. Üçüncü parametre, threadin çalıştıracağı işlevi tanımlayan bir fonksiyon göstericisidir. Dördüncü parametre ise, işlevin çalıştırılması sırasında kullanılacak verileri tutan bir değişkendir.

pthread_create() fonksiyonu, thread oluşturulurken bir hata oluşursa 0 döndürür. Thread oluşturulurken bir hata olmazsa, fonksiyon 0 dışında bir değer döndürür. Bu değer, oluşturulan threadin tanımlayıcısıdır ve pthread_join() fonksiyonu ile threadin bekletilebilmesi için kullanılır.

### pthread_join

pthread_join() fonksiyonu, C dilinde bir threadin çalışmasını bekletmek için kullanılır. Bu fonksiyon, bir threadin çalışmasını tamamlamasını bekler ve sonra programına devam eder.

Bu fonksiyon, aşağıdaki şekilde kullanılır:

```c
int pthread_join(pthread_t thread, void **retval);
```
Bu fonksiyonun ilk parametresi, bekletilecek threadin tanımlayıcısını tutan bir pthread_t tipinde değişkendir. İkinci parametre ise, threadin çalışması sonucu döndürdüğü verileri tutan bir değişkendir. Bu parametre genellikle NULL olarak ayarlanır.

pthread_join() fonksiyonu, threadin çalışması tamamlandıktan sonra 0 döndürür. Eğer threadin çalışması sırasında bir hata oluşursa, fonksiyon 0 dışında bir değer döndürür.

### pthread_detach

pthread_detach() fonksiyonu, C dilinde bir threadin çalışmasının bekletilmemesi için kullanılır. Bu fonksiyon, bir threadin çalışmasını tamamlamasını beklemez ve programına devam eder. Bu sayede, programın çalışması daha hızlı olur. Threadin çalışmasının "detached" (ayrılmış) hale getirilmesini sağlar. Bu fonksiyon, bir threadin çalışması tamamlandıktan sonra otomatik olarak temizlenmesini sağlar.
Bu fonksiyon, aşağıdaki şekilde kullanılır:

```c
int pthread_detach(pthread_t thread);
```
Bu fonksiyonun tek parametresi, "detached" hale getirilecek threadin tanımlayıcısını tutan bir pthread_t tipinde değişkendir.

pthread_detach() fonksiyonu, threadin "detached" hale getirilmesi sırasında bir hata oluşursa 0 döndürür. Threadin "detached" hale getirilmesi sırasında bir hata olmazsa, fonksiyon 0 döndürür.

"Detached" hale getirilen bir thread, pthread_join() fonksiyonu ile bekletilemez ve bu threadin çalışması tamamlandıktan sonra otomatik olarak temizlenir. Bu, programda hafıza gereksinimlerini azaltır ve programın daha efektif çalışmasını sağlar.

Örnek olarak, aşağıdaki kod bloğu bir thread oluşturur ve bu threadin çalışmasını "detached" hale getirir:

```c
#include <pthread.h>
#include <stdio.h>

void *function(void *arg) 
{
  printf("Thread çalışıyor\n");
  return NULL;
}

int main(int argc, char *argv[]) 
{
  pthread_t thread; // Thread için değişken oluşturulur

  // Thread oluşturulur
  if (pthread_create(&thread, NULL, function, NULL) != 0) 
  {
    printf("Thread oluşturulamadı\n");
    return 1;
  }

  // Thread "detached" hale getirilir
  if (pthread_detach(thread) != 0) 
  {
    printf("Thread detached hale getirilemedi\n");
    return 1;
  }

  printf("Thread tamamlandı\n");
  return 0;
}
```
Bu kod, pthread_create() fonksiyonu ile bir thread oluşturur ve pthread_detach() fonksiyonu ile bu threadin çalışmasını "detached" hale getirir.


## MUTEX nedir?

C dilinde, mutex (mutual exclusion, birbiriyle çelişen) mekanizması, birden fazla thread'in aynı anda aynı verilere erişmesini engelleyen bir yapıdır. Mutex, tek bir thread'in aynı anda verilere erişmesine izin verir ve diğer thread'lerin erişimine engel olur. Bu sayede, verilere aynı anda erişen thread'ler arasında çakışma olmaz ve verilerin hatalı kullanılması önlenir.

C dilinde, mutex kullanımı için pthread.h kütüphanesi kullanılır. Bu kütüphane, mutex oluşturmak, kilitlemek ve kilidini açmak gibi işlemleri yapmak için gerekli fonksiyonları sağlar.

Örnek olarak, aşağıdaki kod bloğu bir mutex oluşturur ve bu mutex'i kullanarak, iki farklı thread'in aynı anda aynı verilere erişmesini engelleyebilir:

```c
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex; // Mutex için değişken oluşturulur
int shared_data = 0; // Paylaşılan veri

void *thread_function(void *arg) 
{
  // Mutex kilidi alınır
  pthread_mutex_lock(&mutex);

  // Paylaşılan veri kullanılır
  shared_data++;
  printf("Thread: shared_data = %d\n", shared_data);

  // Mutex kilidi açılır
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main(int argc, char *argv[]) 
{
  pthread_t thread1, thread2; // Thread için değişkenler oluşturulur

  // Thread oluşturulur
  if (pthread_create(&thread1, NULL, thread_function, NULL) != 0) 
  {
    fprintf(stderr, "Thread oluşturulamadı\n");
    return 1;
  }
  if (pthread_create(&thread2, NULL, thread_function, NULL) != 0) 
  {
    fprintf(stderr, "Thread oluşturulamadı\n");
    return 1;
  }

  // Thread'ler çalıştırılır
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}

```

### pthread_mutex_init

pthread_mutex_init() fonksiyonu, C dilinde bir mutex oluşturmak için kullanılır. Bu fonksiyon, bir mutex değişkenini oluşturur ve bu değişkene mutex özelliklerini atar.

Bu fonksiyon, aşağıdaki şekilde kullanılır:

```c
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
```
Bu fonksiyonun ilk parametresi, oluşturulacak mutex için bir pthread_mutex_t tipinde değişken gerektirir. Bu değişken, oluşturulan mutexin tanımlayıcısını tutar. İkinci parametre ise, mutexin özelliklerini tanımlayan bir pthread_mutexattr_t tipinde değişkendir ve genellikle NULL olarak ayarlanır.

pthread_mutex_init() fonksiyonu, mutex oluşturulurken bir hata oluşursa 0 döndürür. Mutex oluşturulurken bir hata olmazsa, fonksiyon 0 dışında bir değer döndürür.

Örnek olarak, aşağıdaki kod bloğu bir mutex oluşturur:

```c
#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex; // Mutex için değişken oluşturulur

int main(int argc, char *argv[]) {
  // Mutex oluşturulur
  if (pthread_mutex_init(&mutex, NULL) != 0) {
    printf("Mutex oluşturulamadı\n");
    return 1;
  }

  // Mutex kullanılır...

  // Mutex temizlenir
  pthread_mutex_destroy(&mutex);
  return 0;
}
```
Bu kod, pthread_mutex_init() fonksiyonu ile bir mutex oluşturur ve oluşturulan mutex'i pthread_mutex_destroy() fonksiyonu ile temizler.

### pthread_mutex_destroy

pthread_mutex_destroy() fonksiyonu, C dilinde kullanılmış olan bir mutex'i temizlemek için kullanılır. Bu fonksiyon, kullanılmış olan mutex değişkenini ve bu değişkene atanmış olan mutex özelliklerini bellekten siler.

Bu fonksiyon, aşağıdaki şekilde kullanılır:

```c
int pthread_mutex_destroy(pthread_mutex_t *mutex);
```
Bu fonksiyonun tek parametresi, temizlenecek mutex'in tanımlayıcısını tutan bir pthread_mutex_t tipinde değişkendir.

pthread_mutex_destroy() fonksiyonu, mutex temizlenirken bir hata oluşursa 0 döndürür. Mutex temizlenirken bir hata olmazsa, fonksiyon 0 dışında bir değer döndürür.

### pthread_mutex_lock

pthread_mutex_lock() fonksiyonu, C dilinde bir mutex'in kilidini almak için kullanılır. Bu fonksiyon, bir thread'in mutex'e erişimine izin verir ve diğer thread'lerin erişimine engel olur. Bu sayede, mutex'e aynı anda erişen thread'ler arasında çakışma olmaz ve verilerin hatalı kullanılması önlenir.

Bu fonksiyon, aşağıdaki şekilde kullanılır:

```c
int pthread_mutex_lock(pthread_mutex_t *mutex);
```

Bu fonksiyonun tek parametresi, kilidini alınacak mutex'in tanımlayıcısını tutan bir pthread_mutex_t tipinde değişkendir.

pthread_mutex_lock() fonksiyonu, mutex kilidi alınırken bir hata oluşursa 0 döndürür. Mutex kilidi alınırken bir hata olmazsa, fonksiyon 0 dışında bir değer döndürür.

Örnek olarak, aşağıdaki kod bloğu bir mutex oluşturur ve bu mutex'i kilitleyerek, iki farklı thread'in aynı anda aynı verilere erişmesini engelleyebilir:

```c
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex; // Mutex için değişken oluşturulur
int counter = 0; // Paylaşılan veri

void *function1(void *arg) 
{
  // Mutex kilidi alınır
  pthread_mutex_lock(&mutex);

  // Paylaşılan veri kullanılır
  counter++;
  printf("Function 1: counter = %d\n", counter);

  // Mutex kilidi açılır
  pthread_mutex_unlock(&mutex);

  return NULL;
}

void *function2(void *arg) 
{
  // Mutex kilidi alınır
  pthread_mutex_lock(&mutex);

  // Paylaşılan veri kullanılır
  counter++;
  printf("Function 2: counter = %d\n", counter);

  // Mutex kilidi açılır
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main(int argc, char *argv[]) 
{
  pthread_t thread1, thread2; // Thread için değişkenler oluşturulur

  // Thread oluşturulur
  if (pthread_create(&thread1, NULL, function1, NULL) != 0) {
    printf("Thread oluşturulamadı\n");
    return 1;
  }
  if (pthread_create(&thread2, NULL, function2, NULL) != 0) {
    printf("Thread oluşturulamadı\n");
    return 1;
  }

  // Thread'ler çalıştırılır
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}
```
Bu kod, iki farklı thread oluşturur ve bu thread'lerde function1() ve function2() fonksiyonları çalıştırılır. Bu fonksiyonlar, bir mutex kilidi alır ve paylaşılan bir veri değişkenini bir arttırarak kullanır. Bu sayede, iki farklı thread'in aynı anda aynı verilere erişmesi önlenir ve verilerin hatalı kullanılması önlenir.

### pthread_mutex_unlock

pthread_mutex_unlock() fonksiyonu, C dilinde bir mutex'in kilidini açmak için kullanılır. Bu fonksiyon, mutex'e aynı anda erişimine izin verilen thread'ler arasında çakışma olmamasını sağlar.

Bu fonksiyon, aşağıdaki şekilde kullanılır:

```c
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```
Bu fonksiyonun tek parametresi, kilidini açılacak mutex'in tanımlayıcısını tutan bir pthread_mutex_t tipinde değişkendir.

pthread_mutex_unlock() fonksiyonu, mutex kilidi açılırken bir hata oluşursa 0 döndürür. Mutex kilidi açılırken bir hata olmazsa, fonksiyon 0 dışında bir değer döndürür.



## gettimeofday nedir?

```c
int gettimeofday( struct timeval *, struct tzp *);
```

gettimeofday() işlevi , geçerli Eşgüdümlü Evrensel Saati (UTC) alır ve onu tp ile işaret edilen zamansal yapıya yerleştirir . tzp NULL değilse, saat dilimi bilgisi tzp tarafından gösterilen saat dilimi yapısında döndürülür.

timeval yapısı time_t değişkeni ve suseconds_t değişkeni olmak üzere iki üye içerir . Birincisi, , bir time_t değeridir, 1 Ocak 1970'ten bu yana geçen saniye sayısıdır. İkincisi, bilgisayarın bildiği ancak time_t değerine dahil edilmeyen bir mikrosaniye değeridir.tv_sectv_usectv_sec

tzp yapısı, zaman dilimi bilgileriyle ilgili iki üye içerir: sistemin geçerli saat dilimi için GMT'nin batısındaki dakika sayısı olan int . tz_minuteswestBazı üyeler tz_dsttime, yaz saati uygulaması için ayarlanacak saat sayısını gösteren bir tam sayıdır. Bunlar, diğer zaman fonksiyonlarında hemen bulunmayan zaman detaylarıdır.

gettimeofday () işlevi, başarı durumunda 0, başarısızlık durumunda -1 döndürür. errno değişkeni, işlev başarısız olduğunda ayarlanır.

## timeval

timeval, C dilinde bir tarih ve zaman veri yapısıdır. 
Bu veri yapısı, bir zaman dilimi içerisinde bir zaman noktasını tanımlamak için kullanılır. 
timeval veri yapısı, iki öğe içerir: tv_sec ve tv_usec. 
tv_sec, bir zaman dilimi içerisindeki saniye cinsinden zamanı tanımlar ve 
tv_usec, bu saniyenin binde bir cinsinden zamanı tanımlar.

timeval veri yapısı, genellikle gettimeofday() fonksiyonu ile kullanılır. 
Bu fonksiyon, sistem saatini ve zaman dilimini saniye cinsinden ve binde bir cinsinden döndürür. 

# Araştırılması gereken şeyler dışında aslında bir yol haritası da çizmek istedim

Bu nedenle bu projede ne yapmalıyız biz?
Çalıştırırken projeyi argüman almalıyız bu argümanlar 5 veya 6 adet olmalı

Bir kaç argüman almalıyız ama ne bu argümanlar?
```
av[1] = filozof sayımız
av[2] = ölüm zamanımız
av[3] = yemek yeme zamanımız
av[4] = uyuma zamanımız
```
Verilerimiz integersa hepsinin sayı olup olmadığına bakmalıyız
ayrıca bu veriler integer olmalı bizim argümanlarımızı integer yapmak için atoi'ye ihtiyacımız olacak

ft_atoi ekledim is_digit ekledim kontrollerimi yaptım şimdi ne yapmalıyım?
Verilerimi struct yapımdaki değişkenlerime vermeliyim
```c 
arg->nbr_philo = ft_atoi(av[1]);
arg->time_to_die = ft_atoi(av[2]);
arg->time_to_eat = ft_atoi(av[3]);
arg->time_to_sleep = ft_atoi(av[4]);
```

Burada ./philo dahil 5 argüman var biliyorum peki 6. ne?

```c
arg->nbr_of_meals = ft_atoi(av[5]);
```
