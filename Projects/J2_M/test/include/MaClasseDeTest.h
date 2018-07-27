#ifndef MACLASSEDETEST_H
#define MACLASSEDETEST_H


class MaClasseDeTest
{
    public:
        MaClasseDeTest();
        virtual ~MaClasseDeTest();
        string Getname() { return m_name; }
        void Setname(string val) { m_name = val; }
        string Gettype_calcul() { return m_type_calcul; }
        void Settype_calcul(string val) { m_type_calcul = val; }
        string Getversion() { return m_version; }
        void Setversion(string val) { m_version = val; }
    protected:
    private:
        string m_name;
        string m_type_calcul;
        string m_version;
};

#endif // MACLASSEDETEST_H
