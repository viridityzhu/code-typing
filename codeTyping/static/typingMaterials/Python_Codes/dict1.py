
m={'a':10,'b':34,'A':7,'Z':3}
m_f={
    k.lower():m.get(k.lower(),0)+m.get(k.upper(),0)
    for k in m.keys()
    if k.lower() in ['a','b']

    }
print(m_f)
