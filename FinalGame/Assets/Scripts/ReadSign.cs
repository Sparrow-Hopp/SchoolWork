using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ReadSign : MonoBehaviour
{
    public GameObject SignText;
    
    void OnTriggerEnter2D (Collider2D col)
    {
        SignText.SetActive(true);
    }
    void OnTriggerExit2D (Collider2D col)
    {
        SignText.SetActive(false);
    }
}
