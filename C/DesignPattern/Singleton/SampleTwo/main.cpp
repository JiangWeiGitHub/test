#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton *GetInstance()
    {
        if (m_Instance == NULL )
        {
            //Lock(); // C++ has no lock lib
            if (m_Instance == NULL )
            {
                m_Instance = new Singleton ();
            }

            //UnLock();
        }
        return m_Instance;
    }

    static void DestoryInstance()
    {
        if (m_Instance != NULL )
        {
            delete m_Instance;
            m_Instance = NULL ;
        }
    }

    int GetTest()
    {
        return m_Test;
    }

private:
    Singleton(){ m_Test = 22; }
    static Singleton *m_Instance;
    int m_Test;
};

Singleton *Singleton ::m_Instance = NULL;

int main(void)
{
    Singleton *singletonObj = Singleton ::GetInstance();
    cout<<singletonObj->GetTest()<<endl;
    Singleton ::DestoryInstance();

    return 0;
}
