using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class Square : MonoBehaviour
{
    public Vector2Int gridPosition;
    public Material mouseOverMaterial; //Drag MouseOverMaterial into Square prefab's Square script to assign.
    //When the mouse hovers over the GameObject, it turns to this color
    static Color mouseOverColor;
    //This stores the GameObject’s original color
    Color originalColor;
    //create a Hidden Color to discover
    public Color hiddenColor;
    //Is the Square active?
    public bool isActive = false;
    
    //Get the GameObject’s spriteRenderer to access the GameObject’s material and color
    SpriteRenderer spriteRenderer; //A spriteRenderer to get and swap colors
    void Awake()
    {
        //Get the spriteRenderer component from the GameObject
        spriteRenderer = GetComponent<SpriteRenderer>();
        //Get the original color of the GameObject
        originalColor = spriteRenderer.material.color;
        mouseOverColor = mouseOverMaterial.color;
        //mouseOverColor = Resources.Load<Material>("Materials/MouseOverColor").color;
        // avoid using Resources if you want to build the project see:
        // https://unity3d.com/learn/tutorials/topics/best-practices/resources-folder
    }
    void Start()
    {
    }
    //OnMouseOver() tells Unity what should happen when a mouse is over the object
    void OnMouseOver()
    {
        //Debug.Log(name); //unity implicitly defines "name" for you to get the "name" of the object.
        GameManager.UpdateUI(this); //the keyword "this" refers to the current object, aka "this" object.
        //spriteRenderer.material.color = mouseOverColor; //change color while mouse is over the object
    }
    void OnMouseDown()
    {
        GameManager.OnDown(this);
    }
    void OnMouseExit()
    {
        GameManager.UpdateUI();
    }
    public void SetColor(Color color)
    {
        spriteRenderer.material.color = color;
    }
    public void ResetColor()
    {
        spriteRenderer.material.color = originalColor;
    }
    public void ShowColor()
    {
        spriteRenderer.material.color = hiddenColor;
    }
    public Color GetColor()
    {
        return spriteRenderer.material.color;
    }
    public void SetActive(bool isActive)
    {
        this.gameObject.SetActive(isActive);
    }
}