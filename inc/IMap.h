#ifndef INTERVALTREE_IMAP_H
#define INTERVALTREE_IMAP_H
#pragma once
#include <iostream>
#include <map>

namespace Interval
{
    template<typename Key, typename Value>
    class intervalMap {

        Value m_defaultVal;
        std::map<Key,Value> m_map;


    public:

        explicit intervalMap(Value const& defVal) : m_defaultVal(defVal) { }
        const Value& operator[](const Key& key) const;
        bool assert(const Key& begin, const Key& end, const Value& value);

    };

    template<typename Key, typename Value>
    const Value& intervalMap<Key,Value>::operator[](const Key& key) const
    {
        auto firstAfter = m_map.upper_bound(key);

        if(firstAfter == m_map.begin()) return m_defaultVal;

        else return (--firstAfter)->second;
    }

    template<typename Key, typename Value>
    bool intervalMap<Key,Value>::assert(const Key& begin, const Key& end, const Value& value)
    {
        if (begin > end) return false;

        const auto beginVal = intervalMap::operator[](begin);
        const auto endVal = intervalMap::operator[](end);

        if(beginVal == value)
        {
            if(endVal == value)
            {
                m_map.erase(m_map.upper_bound(begin),m_map.end());
            }
            else
            {
                m_map[end] = endVal;
                m_map.erase(m_map.upper_bound(begin),m_map.find(end));
            }
        }
        else
        {
            if(endVal == value)
            {
                m_map[begin] = value;
                m_map.erase(m_map.upper_bound(begin),m_map.end());
            }
            else
            {
                m_map[begin] = value;
                m_map.erase(m_map.upper_bound(begin),m_map.find(end));
            }

        }
        return true;
    }

}

#endif //INTERVALTREE_IMAP_H
