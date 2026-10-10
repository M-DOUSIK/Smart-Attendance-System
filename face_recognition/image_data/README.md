# Training images

Add one folder per person, named after them, containing 20–30 clear, front-facing photos:

```
image_data/
├── alice/
│   ├── 01.jpg
│   └── ...
└── bob/
    └── ...
```

Then run `python trainer.py` from `face_recognition/` to generate `trainner.yml` and `labels.pickle`.

Photos are personal data. Only use images of people who have agreed to it, and keep them out of version control (they are ignored by `.gitignore`).
