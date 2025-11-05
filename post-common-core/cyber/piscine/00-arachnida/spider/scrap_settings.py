from dataclasses import dataclass


@dataclass
class ScrapSettings:

    root_url: str
    output: str
    limit: int
