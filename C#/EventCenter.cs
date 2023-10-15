using System;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Example of EventNameEnum
/// </summary>
public enum EventName
{
    Say,
}

public static class EventCenter
{
    private static Dictionary<EventName, List<Delegate>> eventDict = new Dictionary<EventName, List<Delegate>>();

    /// <summary>
    /// 注册时间，T为注册方法的类型 如Action, Action<int> 等
    /// </summary>
    /// <param name="eventName"></param>
    /// <param name="callBack"></param>
    public static void Register<T>(EventName eventName, T callBack) where T : Delegate
    {
        if (!eventDict.TryGetValue(eventName, out var delegateList))
        {
            delegateList = new List<Delegate>() {callBack};
            eventDict.Add(eventName, delegateList);
            //第一次注册成功后也返回false，不然会重复注册两次
            return;
        }

        if (delegateList[0].GetType() != callBack.GetType())
        {
            Debug.LogError(
                $"尝试为事件{eventName}添加不同类型的委托，当前事件所对应的委托是{delegateList[0].GetType()}，要添加的委托类型为{callBack.GetType()}");
            return;
        }

        eventDict[eventName].Add(callBack);
    }

    /// <summary>
    /// 取消指定方法的注册
    /// </summary>
    /// <param name="eventName"></param>
    /// <param name="callBack"></param>
    public static void DeregisterSpecifiedMethod<T>(T callBack) where T : Delegate
    {
        foreach (var delegateList in eventDict.Values)
        {
            for (var i = 0; i < delegateList.Count; i++)
            {
                if (delegateList[i] != callBack) continue;
                delegateList.Remove(delegateList[i]);
                break;
            }
        }
    }
    
    /// <summary>
    /// 将所有和指定对象有关的事件全部移除，一般用于对象被销毁时
    /// </summary>
    /// <param name="registerObj"></param>
    public static void DeregisterSpecifiedObject<T>(T registerObj) where T : class
    {
        foreach (var delegateList in eventDict.Values)
        {
            for (var i = 0; i < delegateList.Count; i++)
            {
                if (delegateList[i].Target.GetType() == registerObj.GetType())
                {
                    delegateList.Remove(delegateList[i]);
                }
            }
        }
    }

    /// <summary>
    /// 取消所有的注册
    /// </summary>
    public static void DeregisterAll()
    {
        eventDict.Clear();
    }

    /// <summary>
    /// Fire之前检测有没有对应该事件名的事件
    /// </summary>
    /// <param name="eventName"></param>
    /// <returns></returns>
    private static List<Delegate> FireCheck(EventName eventName)
    {
        if (eventDict.TryGetValue(eventName, out var delegateList)) return delegateList;
        Debug.LogError($"没有找到事件名为{eventName}的事件");
        return null;
    }

    /// <summary>
    /// 无参委托的事件调用,后面是不同个数参数类型的重载。
    /// </summary>
    /// <param name="eventName"></param>
    public static void Fire(EventName eventName)
    {
        foreach (var d in FireCheck(eventName))
        {
            ((Action) d).Invoke();
        }
    }
    
    public static void Fire<T1>(EventName eventName, T1 arg1)
    {
        foreach (var d in FireCheck(eventName))
        {
            ((Action<T1>) d).Invoke(arg1);
        }
    }

    public static void Fire<T1, T2>(EventName eventName, T1 arg1, T2 arg2)
    {
        foreach (var d in FireCheck(eventName))
        {
            ((Action<T1, T2>) d).Invoke(arg1, arg2);
        }
    }

    public static void Fire<T1, T2, T3>(EventName eventName, T1 arg1, T2 arg2, T3 arg3)
    {
        foreach (var d in FireCheck(eventName))
        {
            ((Action<T1, T2, T3>) d).Invoke(arg1, arg2, arg3);
        }
    }

    public static void Fire<T1, T2, T3, T4>(EventName eventName, T1 arg1, T2 arg2, T3 arg3, T4 arg4)
    {
        foreach (var d in FireCheck(eventName))
        {
            ((Action<T1, T2, T3, T4>) d).Invoke(arg1, arg2, arg3, arg4);
        }
    }
}