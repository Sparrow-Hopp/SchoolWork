using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class Heart : MonoBehaviour
{
    public Sprite[] sprites; //assignment of this array is done in the Unity Inspector
    public int currentHealth = 4;//the current health of this heart
    public int maxHealth = 4;//the max health of this heart
    public float crossFadeToAlpha = 0f; //CrossFadeAlpha value from 0..1
    public float crossFadeToOpaque = 1f; //CrossFadeAlpha value from 0..1
    public float crossFadeTime = 3f; //CrossFade time in seconds
    bool isIgnoreTime = false; //CrossFadeAlpha ignore time? true false?
    Image image;//Point to the Image component on the heart

    public void Start()
    {
        image = GetComponent<Image>();
        SetSprite();
    }
    [ContextMenu("Damage")] //Allow Damage() function to be visible in the inspector
    public void Damage() //A quick function to cause damage...
    {
        if (currentHealth > 0)
        {
            currentHealth--;
            SetSprite();
        }
        if (currentHealth == 0)
        {
            image.sprite = sprites[currentHealth];
            image.CrossFadeAlpha(crossFadeToAlpha, crossFadeTime, isIgnoreTime);
        }
    }
    public void Damage(int damage) //Overload of Damage to take a damage int parameter
    {
        if (currentHealth > 0)
        {
            currentHealth -= damage + 1;
            SetSprite();
        }
        if (currentHealth == 0)
        {
            image.sprite = sprites[currentHealth];
            image.CrossFadeAlpha(crossFadeToAlpha, crossFadeTime, isIgnoreTime);
        }
    }
    void SetSprite() //Set Sprite will swap the image based on the currentHealth:
    {
        image.sprite = sprites[currentHealth];
    }
    [ContextMenu("Reset Health")]
    public void Reset()
    {
        currentHealth = maxHealth;
        SetSprite();
        image.CrossFadeAlpha(crossFadeToOpaque, crossFadeTime, isIgnoreTime);
    }
}