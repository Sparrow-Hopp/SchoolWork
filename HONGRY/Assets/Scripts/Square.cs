using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Square : MonoBehaviour
{
    public Vector2Int gridPosition;

    //OnMouseOver() tells Unity what should happen when a mouse is over the object
    void OnMouseOver()
    {
        Debug.Log(name); //unity implicitly defines "name" for you to get the "name" of the object.
        GridManager.UpdateUI(this); //the keyword "this" refers to the current object, aka "this" object.
    }

    void OnMouseExit()
    {
        GridManager.UpdateUI();
    }
}